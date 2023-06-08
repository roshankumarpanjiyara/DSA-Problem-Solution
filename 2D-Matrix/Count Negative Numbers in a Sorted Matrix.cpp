class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      //approach 1
        int count = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] < 0){
                    count++;
                }
            }
        }

        return count;

      //approach 2
        int count = 0;
        for(int i = 0;i<grid.size();i++){
            int l = 0;
            int r = grid[0].size()-1;

            while(l <= r){
                int mid = l+((r-l)/2);
                if(grid[i][mid] >= 0){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }

            cout<<l<<endl;

            count += (grid[0].size() - l);
        }

        return count;

      //approach 3
        int row = grid.size()-1;
        int col = 0;
        int count = 0;

        while(row >= 0 && col < grid[0].size()){
            if(grid[row][col] >= 0){
                col++;
            }else{
                count += (grid[0].size() - col);
                row--;
            }
        }

        return count;
    }
};
