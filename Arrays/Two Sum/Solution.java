class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> check = new HashMap<>();
        int []result = new int[2];
        for(int i = 0;i<nums.length;i++){
            if(check.containsKey(target-nums[i])){
                result[1] = i;
                result[0] = check.get(target-nums[i]);
                return result;
            }
            check.put(nums[i],i);
        }
        return result;
    }
}
