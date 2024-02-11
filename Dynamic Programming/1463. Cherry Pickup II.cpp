class Solution {
public:
    int t[72][72][72];
    int solve(vector<vector<int>>& grid, int row, int col1, int col2){
        if(row >= grid.size()){
            return 0;
        }

        if(t[row][col1][col2] != -1){
            return t[row][col1][col2];
        }

        int cherry = grid[row][col1];
        if(col1 != col2){
            cherry += grid[row][col2];
        }

        int ans = 0;
        for(int val1 = -1;val1<=1;val1++){
            for(int val2=-1;val2<=1;val2++){
                int newCol1 = col1 + val1;
                int newCol2 = col2 + val2;
                int newRow = row + 1;

                if(newCol1 >= 0 && newCol2 >= 0 && newCol1 < grid[0].size() && newCol2 < grid[0].size()){
                    ans = max(ans, solve(grid, newRow, newCol1, newCol2));
                }
            }
        }

        return t[row][col1][col2] = ans + cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(t, -1, sizeof(t));
        return solve(grid, 0, 0, grid[0].size()-1);
    }
};
