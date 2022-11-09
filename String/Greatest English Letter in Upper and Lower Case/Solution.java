class Solution {
    public String greatestLetter(String s) {
        int[] lower = new int[26];
        int[] upper = new int[26];

        for(int i = 0;i<s.length();i++){
            if(s.charAt(i)>='a' && s.charAt(i)<='z'){
                lower[s.charAt(i)-'a']++;
            }else{
                upper[s.charAt(i)-'A']++;
            }
        }
        String ans = "";
        for(int i = 26-1;i>=0;i--){
            if(lower[i] >= 1 && upper[i] >= 1){
                ans += (char)(65+i);
                return ans;
            }
        }
        return ans;
    }
}
