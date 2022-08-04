class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        Stack<Character> check = new Stack<>();
        for(int i = 0;i<n;i++){
            char c = s.charAt(i);
            if(c == '('){
                check.push(')');
            }else if(c == '{'){
                check.push('}');
            }else if(c == '['){
                check.push(']');
            }else if(check.isEmpty() || check.pop() != c){
                return false;
            }
        }
        return check.isEmpty();
    }
}
