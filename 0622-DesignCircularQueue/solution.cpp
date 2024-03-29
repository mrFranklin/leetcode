class MyCircularQueue {
public:
    vector<int> v;
    int head;
    int tail;
    int cap;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        v.assign(k+1, 0);
        head = 0;
        tail = 0;
        cap = k + 1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        v[tail] = value;
        tail = (tail + 1) % cap;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % cap;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return v[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        int n = (tail - 1 + cap) %cap;
        return v[n];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == tail;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return head == (tail + 1) % cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */