class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator>mp;
    list<pair<int, int>>dq;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(mp.count(key) == 0)
            return -1;
        
        auto t = mp[key];
        int val = t->second;
        dq.erase(t);
        dq.push_back({key, val});
        auto it = dq.end();
        it--;
        mp[key] = it;
        return val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            auto it = mp[key];
            dq.erase(it);
        }
        else if(mp.size() == n){
            int k = dq.front().first;
            mp.erase(k);
            dq.pop_front();
        }
         dq.push_back({key, value});
        auto it = dq.end();
        it--;
        mp[key] = it;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */