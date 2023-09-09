class Solution {
public:
    // int ans = 0;
    int t[202][1001];
    int solve(int idx, vector<int>& nums, int target){
        if(idx >= nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        if(t[idx][target] != -1){
            return t[idx][target];
        }
        int take = 0;
        if(nums[idx] <= target){
            take = solve(0, nums, target - nums[idx]);
        }
        int no_take = solve(idx +1, nums, target);

        return t[idx][target] = take + no_take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(t, -1, sizeof(t));
        return solve(0, nums, target);
        // return ans;
    }
};
