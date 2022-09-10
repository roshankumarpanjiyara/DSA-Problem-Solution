class Solution {
    public int majorityElement(int[] nums) {
        int ansIdx = 0;
        int count = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i] == nums[ansIdx]){
                count++;
            }else{
                count--;
            }
            if(count == 0){
                ansIdx = i;
                count = 1;
            }
        }
        return nums[ansIdx];
    }
}
