class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr;

        arr.push_back(pref[0]);

        for(int i = 1;i<pref.size();i++){
            arr.push_back(pref[i-1]^pref[i]);
        }

        return arr;
    }
};
