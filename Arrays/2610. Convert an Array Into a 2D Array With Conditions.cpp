class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(nums.size() + 1);
        vector<vector<int>> res;

        for(int i : nums){
            if(freq[i] >= res.size()){
                res.push_back({});
            }
            res[freq[i]].push_back(i);
            freq[i]++;
        }

        return res;
    }
};
