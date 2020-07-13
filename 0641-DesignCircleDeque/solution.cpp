class MyCircularDeque {
public:
    vector<int> v;
    int head;
    int tail;
    int cap;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        v.assign(k+1, 0);
        head = 0;
        tail = 0;
        cap = k + 1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        head = (head - 1 + cap) % cap;
        v[head] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        v[tail] = value;
        tail = (tail + 1) % cap;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % cap;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        tail = (tail - 1 + cap) % cap;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return v[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        int n = (tail - 1 + cap) %cap;
        return v[n];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return head == tail;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return head == (tail + 1) % cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */