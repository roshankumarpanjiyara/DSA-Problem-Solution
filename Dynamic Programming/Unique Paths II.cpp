class Solution {
public:
    int n, m;
    int t[101][101];
    int solve(int i, int j, vector<vector<int>>& obstacleGrid){
        if(i >= n || i < 0 || j >= m || j < 0 || obstacleGrid[i][j] == 1){
            return 0;
        }

        if(i == n-1 && j == m-1){
            return 1;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int right = solve(i, j+1, obstacleGrid);
        int down = solve(i+1, j, obstacleGrid);

        return t[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, obstacleGrid);
    }
};
