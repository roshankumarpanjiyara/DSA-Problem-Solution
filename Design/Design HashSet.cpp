class MyHashSet {
public:
    int M;
    vector<list<int>> buckets;

    int getIdx(int key){
        return key%M;
    }

    MyHashSet() {
        M = 15000;
        buckets = vector<list<int>>(M, list<int>{});
    }
    
    void add(int key) {
        int idx = getIdx(key);
        auto itr = find(buckets[idx].begin(), buckets[idx].end(), key);

        if(itr == buckets[idx].end()){
            buckets[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = getIdx(key);
        auto itr = find(buckets[idx].begin(), buckets[idx].end(), key);

        if(itr != buckets[idx].end()){
            buckets[idx].erase(itr);
        }
    }
    
    bool contains(int key) {
        int idx = getIdx(key);
        auto itr = find(buckets[idx].begin(), buckets[idx].end(), key);

        return itr != buckets[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
