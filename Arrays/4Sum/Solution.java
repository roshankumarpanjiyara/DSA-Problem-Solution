class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        if(nums == null || nums.length == 0){
            return ans;
        }
        Arrays.sort(nums);
        for(int i = 0;i<nums.length-1;i++){
            for(int j = i+1;j<nums.length;j++){
                long target2 = (long)target - (long)nums[i] - (long)nums[j];
                int s = j+1;
                int e = nums.length-1;
                while(s<e){
                    long sum = (long)nums[s]+(long)nums[e];
                    if(sum == target2){
                        ArrayList<Integer> quad = new ArrayList<>();
                        quad.add(nums[i]);
                        quad.add(nums[j]);
                        quad.add(nums[s]);
                        quad.add(nums[e]);
                        ans.add(quad);
                        while(s<e && nums[s] == quad.get(2)){
                            ++s;
                        }
                        while(s<e && nums[e] == quad.get(3)){
                            --e;
                        }
                    }else if(sum>target2){
                        e--;
                    }else{
                        s++;
                    }
                }
                while(j+1<nums.length && nums[j+1] == nums[j]){
                    ++j;
                }
            }
            while(i+1<nums.length && nums[i] == nums[i+1]){
                ++i;
            }
        }
        return ans;
    }
}
