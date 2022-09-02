class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix[0].length;
        int m = matrix.length;
      
      //solution 1
        int row[] = new int[n];
        int col[] = new int[m];
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0){
                    row[j] = 1;
                    col[i] = 1;
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(row[j] == 1 || col[i] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
        
        
        //solution 2
        int col0 = 1;
        for(int i = 0;i<m;i++){
            if(matrix[i][0] == 0){
                col0 = 0;
            }
            for(int j = 1;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=1;j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0){
                matrix[i][0] = 0;
            }
        }
    }
}
