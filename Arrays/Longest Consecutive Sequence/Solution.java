//approach 1
class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        Arrays.sort(nums);
        int curcount = 1;
        int maxcount = 1;
        for(int i = 1;i<nums.length;i++){
            if(nums[i] != nums[i-1]){
                if(nums[i]-nums[i-1] == 1){
                    curcount++;
                }else{
                    maxcount = Math.max(curcount,maxcount);
                    curcount = 1;
                }
            }
            // System.out.print(curcount+" ");
        }
        return Math.max(curcount,maxcount);
    }
}

//approach 2
class Solution {
    public int longestConsecutive(int[] nums) {
        HashMap<Integer, Boolean> check = new HashMap<>();
        for(int i = 0;i<nums.length;i++){
            check.put(nums[i],true);
        }
        for(int i = 0;i<nums.length;i++){
            if(check.containsKey(nums[i] - 1)){
                check.put(nums[i],false);
            }
        }
        int max = 0;
        for(Integer key:check.keySet()){
            if(check.get(key) == true){
                max = Math.max(max,findLength(check,key));
            }
        }
        return max;
    }
    public int findLength(HashMap <Integer,Boolean> check, int key){
        int ans = 0;
        while(check.containsKey(key)){
            ans++;
            key++;
        }
        return ans;
    }
}
