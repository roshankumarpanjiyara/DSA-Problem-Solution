class RandomizedSet {
public:
    vector<int> vt;
    unordered_map<int, int> mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()){
            return false;
        }

        vt.push_back(val);
        mp[val] = vt.size()-1;

        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }
        int idx = mp[val];
        int lastElement = vt.back();

        vt.back() = val;
        vt[idx] = lastElement;
        mp[lastElement] = idx;

        vt.pop_back();
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        int randomIdx = rand() % vt.size();
        return vt[randomIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
