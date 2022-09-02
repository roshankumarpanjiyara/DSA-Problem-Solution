class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        // for(int i = 0;i<m;i++){
        //     for(int j = 0;j<n;j++){
        //         if(target == matrix[i][j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        int lo = 0;
        int h = m*n-1;
        while(lo<=h){
            int mid = lo+(h-lo)/2;
            if(matrix[mid/n][mid%n] == target){
                return true;
            }else if(matrix[mid/n][mid%n] < target){
                lo = mid+1;
            }else{
                h = mid-1;
            }
        }
        return false;
    }
}
