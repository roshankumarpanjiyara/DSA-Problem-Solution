class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        int diff = arr[1]-arr[0];
        for(int i = 1;i<arr.length-1;i++){
            int d = arr[i+1] - arr[i];
            if(d != diff){
                return false;
            }
        }
        return true;
    }
}
