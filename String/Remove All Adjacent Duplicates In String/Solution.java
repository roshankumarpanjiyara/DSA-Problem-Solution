class Solution {
    public String removeDuplicates(String s) {
        if(s == null || s.length() == 0){
            return s;
        }
        Stack<Character> check = new Stack<Character>();
        String ans = "";
        for(int i = 0;i<s.length();i++){
            char ch = s.charAt(i);
            if(!check.isEmpty()){
                if(check.peek() != ch){
                    check.push(ch);
                }else{
                    check.pop();
                }
            }else{
                check.push(ch);
            }
        }
        // System.out.println(check);
        for(char ch : check){
            ans += ch;
        }
        return ans;
    }
}
