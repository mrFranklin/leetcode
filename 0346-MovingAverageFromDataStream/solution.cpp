class MovingAverage {
public:
    queue<int> q;
    int cap;
    int sum;

    /** Initialize your data structure here. */
    MovingAverage(int size) {
        cap = size;
        sum = 0;
    }
    
    double next(int val) {
        if (q.size() < cap) {
           sum += val;
           q.push(val);
        } else {
            sum += val - q.front();
            q.pop();
            q.push(val);
        }
        return (double)sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */