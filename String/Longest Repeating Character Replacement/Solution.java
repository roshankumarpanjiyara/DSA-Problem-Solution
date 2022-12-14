class Solution {
    public int characterReplacement(String s, int k) {
        int n = s.length();
        int max_length = 0;
        int max_count = 0;
        int start = 0;
        int[] chars = new int[26];
        for(int i = 0;i<s.length();i++){
            chars[s.charAt(i)-'A']++;
            max_count = Math.max(max_count,chars[s.charAt(i)-'A']);

            while(i - start - max_count + 1 > k){
                chars[s.charAt(start)-'A']--;
                start++;
            }

            max_length = Math.max(max_length,i-start+1);
        }
        return max_length;
    }
}
