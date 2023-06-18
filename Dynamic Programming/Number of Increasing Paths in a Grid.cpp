class Solution {
public:
    int n, m;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    int mod = 1e9+7;
    int dp[1001][1001];
    int dfs(int i, int j, vector<vector<int>>& grid){
        int result = 1;

        if(dp[i][j] != -1){
            return dp[i][j]%mod;
        }

        for(int d = 0;d < 4;d++){
            int ni = i + dx[d];
            int nj = j + dy[d];

            if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] < grid[i][j]){
                result = (result%mod + dfs(ni, nj, grid)%mod)%mod;
            }
        }

        return dp[i][j] = result%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                ans = (ans%mod + dfs(i,j,grid)%mod)%mod;
            }
        }
        return ans%mod;
    }
};
