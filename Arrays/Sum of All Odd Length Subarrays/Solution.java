class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int ans = 0;
        for(int i = 0;i<arr.length;i++){
            int totalSubArray = (arr.length-i)*(i+1);
            if(totalSubArray%2 == 0){
                ans += (totalSubArray/2)*arr[i];
            }else{
                ans += ((totalSubArray/2)+1)*arr[i];
            }
        }
        return ans;
    }
}
