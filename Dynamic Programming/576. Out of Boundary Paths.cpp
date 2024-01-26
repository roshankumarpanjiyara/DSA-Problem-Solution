class Solution {
public:
    int dr[4] = {-1, 0 , 1 ,0};
    int dc[4] = {0, -1 , 0 ,1};
    int t[51][51][51];
    int MOD = 1e9+7;
    int solve(int m, int n, int maxMove, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return 1;
        }
        if(maxMove == 0){
            return 0;
        }

        if(t[i][j][maxMove] != -1){
            return t[i][j][maxMove];
        }
        // int up = solve(m, n, maxMove - 1, i - 1, j);
        // int down = solve(m, n, maxMove - 1, i + 1, j);
        // int right = solve(m, n, maxMove - 1, i, j - 1);
        // int left = solve(m, n, maxMove - 1, i, j + 1);

        int result = 0;

        for(int k = 0; k<4;k++){
            result = (result % MOD + solve(m , n, maxMove - 1, i + dr[k], j + dc[k])) % MOD;
        }

        // return up + down + right + left;
        return t[i][j][maxMove] = result;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(t, -1, sizeof(t));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};
