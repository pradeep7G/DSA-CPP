class LRUCache {
public:
    unordered_map<int,int> keyvalue;
    unordered_map<int,list<int>::iterator> keyiter;
    list<int> lru;
    int size;
    LRUCache(int capacity) {
        this->size=capacity;
    }
    
    int get(int key) {
       if(keyvalue.count(key)==0)
           return -1;
        updateLru(key);
        return keyvalue[key];
    }
    
    void put(int key, int value) {
       if(keyvalue.size()==size && keyvalue.count(key)==0){
           evict();
       }
       updateLru(key);
       keyvalue[key]=value;
    }
    void updateLru(int key){
        if(keyvalue.count(key))
            lru.erase(keyiter[key]);
        lru.push_front(key);
        keyiter[key]=lru.begin();
    }
    void evict(){
        keyvalue.erase(lru.back());
        keyiter.erase(lru.back());
        lru.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */