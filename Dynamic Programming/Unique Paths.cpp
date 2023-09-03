class Solution {
public:
    int M, N;
    int t[101][101];
    int solve(int i, int j){
        if(i >= M || j >= N){
            return 0;
        }
        if(i == M-1 && j == N-1){
            return 1;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int down = solve(i+1, j);
        int right = solve(i, j+1);

        return t[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        memset(t, -1, sizeof(t));
        return solve(0, 0);
    }
};
