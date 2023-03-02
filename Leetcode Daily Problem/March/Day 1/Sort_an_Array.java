class Solution {
    public int[] sortArray(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int min = nums[0];
        int max = nums[0];

        for(int i = 0;i<nums.length;i++){
            map.put(nums[i],map.getOrDefault(nums[i],0)+1);

            min = Math.min(nums[i], min);
            max = Math.max(nums[i], max);
        }

        int i = 0;
        for(int j = min; j<= max; j++){
            if(map.containsKey(j)){
                while(map.get(j)>0){
                    nums[i] = j;
                    map.put(j, map.get(j)-1);
                    i++;
                }
            }
        }

        return nums;
    }
}
