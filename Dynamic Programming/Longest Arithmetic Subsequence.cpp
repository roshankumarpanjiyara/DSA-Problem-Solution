class Solution {
public:
    // int solve(vector<int>& nums, int diff, int i){
    //     if(i < 0){
    //         return 0;
    //     }
    //     int ans = 0;
    //     for(int j = i-1;j>=0;j--){
    //         if(nums[i] - nums[j] == diff){
    //             ans = max(ans, 1 + solve(nums, diff, j));
    //         }
    //     }
    //     return ans;
    // }
    // int longestArithSeqLength(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n <= 2){
    //         return n;
    //     }

    //     int ans = 0;
    //     for(int i = 0;i<n;i++){
    //         for(int j = i+1;j<n;j++){
    //             ans = max(ans, 2 + solve(nums, nums[j] - nums[i], i));
    //         }
    //     }

    //     return ans;
    // }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }

        int ans = 0;
        unordered_map<int, int> dp[n+1];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                int diff = nums[j] - nums[i];
                int count = 1;
                if(dp[j].count(diff)){
                    count = dp[j][diff];
                }
                dp[i][diff] = 1 + count;
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};
