class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<vector<int>> q;
        q.push({0,0,1});
        visited[0][0] = 1;
        int path = INT_MIN;

        int row = grid.size();
        if (row == 0) return -1;
        int col = grid[0].size();
        if (col == 0 ) return -1;
        if (grid[0][0] != 0 | grid[row-1][col-1] != 0) return -1;

        while(!q.empty()){
            int row = q.front()[0];
            int col = q.front()[1];
            int d = q.front()[2];
            q.pop();
            if(row == n-1 && col == n-1){
                return d;
            }

            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !visited[nrow][ncol] && grid[nrow][ncol] == 0){
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol, d+1});
                    }
                }
            }
        }

        return  -1;
    }
};
