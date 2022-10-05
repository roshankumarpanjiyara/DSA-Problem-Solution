class Solution {
    public String removeOuterParentheses(String s) {
        Stack<Character> check = new Stack<>();
        StringBuilder ans = new StringBuilder();
        for(int i = 0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch == '('){
                if(check.size()>0){
                    ans.append(ch);
                }
                check.push('(');
            }else{
                check.pop();
                if(check.size()>0){
                    ans.append(ch);
                }
            }
        }
        return ans.toString();
    }
}
