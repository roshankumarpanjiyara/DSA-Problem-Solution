class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] result = new int[nums1.length];
        Stack<Integer> check = new Stack<>();
        HashMap<Integer, Integer> fmap = new HashMap<>();
        for(int i = nums2.length-1;i>=0;i--){
            while(!check.isEmpty() && check.peek() <= nums2[i]){
                check.pop();
            }
            int res = check.isEmpty()?-1:check.peek();
            check.push(nums2[i]);
            fmap.put(nums2[i],res);
        }
        for(int i = 0;i<nums1.length;i++){
            result[i] = fmap.get(nums1[i]);
        }
        return result;
    }
}
