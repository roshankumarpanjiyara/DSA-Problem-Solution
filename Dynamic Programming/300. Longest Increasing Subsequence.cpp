class Solution {
public:
    vector<vector<int>> t;
    int solve(int i, int prev, vector<int>& nums){
        if(i >= nums.size()){
            return 0;
        }
        if(t[i][prev + 1] != -1){
            return t[i][prev + 1];
        }
        int not_take = solve(i + 1, prev, nums);
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + solve(i + 1, i, nums);
        }

        return t[i][prev + 1] = max(not_take, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        t.resize(size(nums), vector<int>(1 + size(nums), -1));
        return solve(0, -1, nums);
    }
};
