class Solution {
    public int findKthPositive(int[] arr, int k) {
        int[] missing = new int[k];
        int i = 0;
        int l = 0;
        int j = 1;
        while(true){
            if(i<arr.length && j == arr[i]){
                i++;
                j++;
                // continue;
            }else{
                missing[l] = j;
                j++;
                l++;
            }
            if(l == k){
                break;
            }
        }
        System.out.println(j);
        return missing[k-1];
    }
}
