class Solution {
    public static int firstOcc(int []nums, int target){
        int s = 0;
        int e = nums.length-1;
        int ans = -1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }else if(nums[mid] > target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
    public static int lastOcc(int []nums, int target){
        int s = 0;
        int e = nums.length-1;
        int ans = -1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == target){
                ans = mid;
                s = mid+1;
            }else if(nums[mid] > target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
    public int[] searchRange(int[] nums, int target) {
      //solution 1
        // int first = -1;
        // int sec = -1;
        // for(int i = 0;i<nums.length;i++){
        //     if(nums[i] == target){
        //         if(first == -1){
        //             first = i;
        //             sec = i;
        //         }else{
        //             sec = i;
        //         }
        //     }
        // }
        // return new int[]{first,sec};
      //solution 2
        int first = firstOcc(nums,target);        
        int last = lastOcc(nums,target);
        return new int[]{first,last};
    }
}
