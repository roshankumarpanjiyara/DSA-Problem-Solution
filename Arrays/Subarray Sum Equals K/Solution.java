class Solution {
    public int subarraySum(int[] nums, int k) {
        int cursum = 0;
        int count = 0;
        HashMap<Integer, Integer> check = new HashMap<>();
        for(int i = 0;i<nums.length;i++){
            cursum += nums[i];
            
            if(cursum == k){
                count++;
                // break;
            }
            if(check.containsKey(cursum-k)){
                count += check.get(cursum-k);
                // break;
            }
            check.put(cursum,check.getOrDefault(cursum, 0) + 1);
        }
        return count;
    }
}
