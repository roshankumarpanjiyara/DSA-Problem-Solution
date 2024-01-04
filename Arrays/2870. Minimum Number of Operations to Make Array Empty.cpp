class Solution {
    public int minOperations(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();

        for(int i : nums){
            freq.put(i, freq.getOrDefault(i, 0) + 1);
        }

        int ans = 0;
        for(int i : freq.keySet()){
            if(freq.get(i) == 1){
                return -1;
            }
            ans += Math.ceil((double)freq.get(i)/3.0);
        }

        return ans;
    }
}
