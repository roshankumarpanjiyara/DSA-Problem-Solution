class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(auto &i : nums){
            mp[i]++;
        }

        vector<vector<int>> buckets(n+1);

        for(auto &it: mp){
            int el = it.first;
            int freq = it.second;

            buckets[freq].push_back(el);
        }

        vector<int> res;

        for(int i = n;i>=0;i--){
            if(buckets[i].size() != 0){
                while(buckets[i].size() > 0 && k-- > 0){
                    res.push_back(buckets[i].back());
                    buckets[i].pop_back();
                }
            }
        }
        return res;
    }
};
