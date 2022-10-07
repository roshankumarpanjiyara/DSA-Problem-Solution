class Solution {
    public List<Integer> majorityElement(int[] nums) {
        HashMap<Integer,Integer> check = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        int n = nums.length/3;
        // System.out.println(n);
        for(int i=0;i<nums.length;i++){
            // if(check.get(nums[i])>n){
                if(check.containsKey(nums[i])){
                    check.put(nums[i],check.get(nums[i])+1);
                }else{
                    check.put(nums[i],1);   
                }
            // }
        }
        for(int d:check.keySet()){
            if(check.get(d)>n){
                ans.add(d);
            }
        }
        // System.out.println(check);
        return ans;
    }
}
