class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int len, int low, int high, int zero, int one, vector<int>& dp){
        if(len > high){
            return 0;
        }

        if(dp[len] != -1){
            return dp[len];
        }

        int add = 0;
        if(low <= len && len <= high ){
            add = 1;
        }

        int appendOne = solve(len+one, low, high, zero, one, dp);
        int appendZero = solve(len+zero, low, high, zero, one, dp);

        return dp[len] = (add + appendOne + appendZero) % MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        return solve(0, low, high, zero, one, dp);
    }
};
