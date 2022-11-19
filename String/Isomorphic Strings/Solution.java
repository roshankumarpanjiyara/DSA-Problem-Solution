class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length() != t.length()){
            return false;
        }
        Map<Character,Character> check1 = new HashMap<>();
        Map<Character,Boolean> check2 = new HashMap<>();

        for(int i = 0;i<s.length();i++){
            char ch1 = s.charAt(i);
            char ch2 = t.charAt(i);
            if(check1.containsKey(ch1)){
                if(check1.get(ch1) != ch2){
                    return false;
                }
            }else{
                if(check2.containsKey(ch2)){
                    return false;
                }else{
                    check1.put(ch1,ch2);
                    check2.put(ch2,true);
                }
            }
        }
        return true;
    }
}
