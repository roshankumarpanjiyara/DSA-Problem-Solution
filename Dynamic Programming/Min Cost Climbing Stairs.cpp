class Solution {
public:
    // int min;
    int dp[1001];
    int solve(int i, vector<int>& cost){
        if(i>= cost.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int p1 = cost[i] + solve(i+1,cost);
        int p2 = cost[i] + solve(i+2,cost);

        return dp[i] = min(p1, p2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // min = 0;
        memset(dp, -1, sizeof(dp));
        return min(solve(1, cost), solve(0, cost));
        // return min;
    }
};
