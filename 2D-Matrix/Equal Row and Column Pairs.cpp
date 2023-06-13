class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                bool match = true;
                for(int i = 0;i<m;i++){
                    if(grid[r][i] != grid[i][c]){
                        match = false;
                        break;
                    }
                }
                ans = match == true ? ans+1 : ans;
            }
        }
        return ans;
    }
};
