class LFUCache {
public:
    unordered_map<int,pair<int,int>> keyValue; //key,<value,freqquency> pair
    unordered_map<int,list<int>::iterator> keyIter; //key list iterator map
    unordered_map<int,list<int>> freqMap; //freq , list iterator map
    
    int capacity;
    int minFreq; //track minFreq of lfu cache.
    int size;
    LFUCache(int capacity) {
        this->capacity=capacity;
        minFreq=0;
        size=0;
    }
    
    int get(int key) {
        if(keyValue.find(key)==keyValue.end())
            return -1;
        update(key);
        return keyValue[key].first;
    }
    
    void put(int key, int value) {
        if(capacity<=0)
            return ;
        if(keyValue.find(key)!=keyValue.end()){
            keyValue[key].first=value;
            update(key);
            return ;
        }
        if(size==capacity){
            //remove/evict least frequencly used, if tie least recently used
           int evict=freqMap[minFreq].front();
        freqMap[minFreq].pop_front();
        keyValue.erase(evict);
        keyIter.erase(evict);
        }
        else{
            size++;
        }
        keyValue[key]=make_pair(value,1);
        freqMap[1].push_back(key);
        keyIter[key]= --freqMap[1].end();
        minFreq=1;
    }
    void update(int key){
        int freq=keyValue[key].second;
        auto iter=keyIter[key];
        keyValue[key].second++;
        freqMap[freq].erase(iter);
        freqMap[freq+1].push_back(key);
        keyIter[key]=--freqMap[freq+1].end();
        if(freqMap[minFreq].empty()){
            freqMap.erase(minFreq);
            minFreq++;
        }
    }
    void evict(){
        int evict=freqMap[minFreq].front();
        freqMap[minFreq].pop_front();
        keyValue.erase(evict);
        keyIter.erase(evict);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */