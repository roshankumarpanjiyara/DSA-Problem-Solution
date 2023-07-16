class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& events, int i, int k){
        if(i >= n || k == 0){
            return 0;
        }
        int start = events[i][0];
        int end = events[i][1];
        int value = events[i][2];

        if(dp[i][k] != -1){
            return dp[i][k];
        }

        int skip = solve(events, i + 1, k);
        vector<int> temp({end, INT_MAX, INT_MAX});
        int j = upper_bound(events.begin() + i + 1, events.end(), temp) - events.begin();
        int take = value + solve(events, j, k-1);
        return dp[i][k] = max(skip, take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        dp.resize(n+1, vector<int>(k+1, -1));
        sort(events.begin(), events.end());
        return solve(events, 0, k);
    }
};
