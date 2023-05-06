class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int MOD = 1e9+7;
        sort(begin(nums), end(nums));
        vector<int> power(nums.size());
        power[0] = 1;
        for(int i = 1;i<nums.size();i++){
            power[i] = (power[i-1]*2) % MOD;
        }
        int count = 0;
        while(l<=r){
            if(nums[l] + nums[r] <= target){
                count = ((count % MOD)+ power[r-l]) % MOD;
                l++;
            }else{
                r--;
            }
        }
        return count % MOD;
    }
};
