class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
      //approach 1
        int c[] = new int[m+n];
        int i = 0,j = 0,k = 0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                c[k++] = nums1[i++];
            }else{
                c[k++] = nums2[j++];
            }
        }
        while(j<n){
            c[k++] = nums2[j++];
        }
        while(i<m){
            c[k++] = nums1[i++];
        }
        for(int l = 0;l<m+n;l++){
            nums1[l] = c[l];
        
        
      //approach 2
        int i = 0,j = 0;
        if(m >= 1 && n>=1){
            for(i = 0;i<m;i++){
                if(nums1[i]>nums2[0]){
                    int temp = nums1[i];
                    nums1[i] = nums2[0];
                    nums2[0] = temp;
                    Arrays.sort(nums2);
                }
            }   
        }
        for(i = 0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
       
    }
}
