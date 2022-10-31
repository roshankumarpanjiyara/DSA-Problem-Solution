class Solution {
    public int lengthOfLongestSubstring(String s) {
      //approach 1
        int count = 0;
        if(s.length() == 0 || s == null){
            return 0;
        }
        HashMap<Character,Boolean> check = new HashMap<>();
        for(int i = 0;i<s.length();i++){
            char ch = s.charAt(i);
            if(!check.containsKey(ch)){
                check.put(ch,true);
            }else{
                // System.out.println(i);
                count = Math.max(count,check.size());
                check.clear();
                check.put(ch,true);
            }
            // System.out.println(i);
        }
        count = Math.max(count,check.size());
        return count;
        
      //approach 2
        Map<Character, Integer> check = new HashMap<>();
        int max = 0;
        int j = 0;
        for(int i = 0;i<s.length();i++){
            if(check.containsKey(s.charAt(i))){
                j = Math.max(j,check.get(s.charAt(i))+1);
            }
            check.put(s.charAt(i),i);
            max = Math.max(max,i-j+1);
        }
        return max;
    }
}
