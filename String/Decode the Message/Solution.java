class Solution {
    public String decodeMessage(String key, String message) {
        HashMap<Character, Character> check = new HashMap<>();
        StringBuilder ans = new StringBuilder("");
        int count = 0;
        for(int i = 0;i<key.length();i++){
            char ch = key.charAt(i);
            if(!check.containsKey(ch) && ch != ' '){
                check.put(ch,(char)('a' + count++));
            }
        }
        for(int i = 0;i<message.length();i++){
            char ch = message.charAt(i);
            if(check.containsKey(ch) && ch!= ' '){
                ans.append(check.get(ch));
            }else{
                ans.append(" ");
            }
        }
        return ans.toString();
    }
}
