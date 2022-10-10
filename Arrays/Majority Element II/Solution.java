//approach 1
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

//approach 2
class Solution {
    public static ArrayList<Integer> Solve(int n, int[] nums) {
        // code here
        int num1 = -1;
        int num2 = -1;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == num1){
                count1++;
            }else if(nums[i] == num2){
                count2++;
            }else if(count1 == 0){
                num1 = nums[i];
                count1 = 1;
            }else if(count2 == 0){
                num2 = nums[i];
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        count1 = 0;
        count2 = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == num1){
                count1++;
            }else if(nums[i] == num2){
                count2++;
            }
        }
        if(count1 > n/3){
            ans.add(num1);
        }
        if(count2 > n/3){
            ans.add(num2);
        }
        if(ans.isEmpty()){
            ans.add(-1);
        }
        return ans;
    }
}
