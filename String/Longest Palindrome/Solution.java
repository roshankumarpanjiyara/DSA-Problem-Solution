class Solution {
    public int longestPalindrome(String s) {
        //approach 1
        HashMap<Character,Integer> check = new HashMap<>();
        for(int i = 0;i<s.length();i++){
            char ch = s.charAt(i);
            if(check.containsKey(ch)){
                check.put(ch,check.get(ch)+1);
            }else{
                check.put(ch,1);
            }
        }
        int count = 0;
        boolean firstOdd = false;
        for(int i:check.values()){
            if(i%2 == 0){
                count += i;
            }else{
                if(firstOdd == false){
                    count += i;
                    firstOdd = true;
                }else{
                    count += (i-1);
                }
            }
        }
        return count;
        
        //approach 2
        int[] lower = new int[26];        
        int[] upper = new int[26];
        for(int i = 0;i<s.length();i++){
            char ch = s.charAt(i);
            if((ch-97)>=0){
                lower[ch-97]++;
            }else{
                upper[ch-65]++;
            }
        }
        
        int ans = 0;
        boolean firstOdd = false;
        for(int i = 0;i<26;i++){
            if(lower[i]%2 == 0){
                ans += lower[i];
            }else{
                if(firstOdd == false){
                    ans += lower[i];
                    firstOdd = true;
                }else{
                    ans += lower[i]-1;
                }
            }
        }
        
        for(int i = 0;i<26;i++){
            if(upper[i]%2 == 0){
                ans += upper[i];
            }else{
                if(firstOdd == false){
                    ans += upper[i];
                    firstOdd = true;
                }else{
                    ans += upper[i]-1;
                }
            }
        }
        return ans;
    }
}
