class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> freq;
        int j = 0;
        for(int i = 0;i<nums.size();i++){
            freq[nums[i]]++;
            while(freq[nums[i]] > k){
                freq[nums[j]]--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
