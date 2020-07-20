class Node {
public:
    int key;
    int value;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

// 利用c++自带的list，此时存到map内的是iterator，不然没办法使用list删除这个元素~ 
class LRUCache {
public:
    int cap;
    int count;
    list<Node> l;
    unordered_map<int, list<Node>::iterator> cache;
    LRUCache(int capacity) {
        this->cap = capacity;
        this->count = 0;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        list<Node>::iterator it = cache[key];
        l.push_front(Node(it->key, it->value));
        l.erase(it);
        cache[key] = l.begin();
        return l.front().value;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            list<Node>::iterator it = cache[key];
            l.push_front(Node(key, value));
            l.erase(it);
            cache[key] = l.begin();
        } else {
            if (count >= cap) {
                list<Node>::iterator it = l.end();
                it--;
                cache.erase(it->key);
                l.pop_back();
            } else {
                count++;
            }
            Node node = Node(key, value);
            l.push_front(node);
            cache[key] = l.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
