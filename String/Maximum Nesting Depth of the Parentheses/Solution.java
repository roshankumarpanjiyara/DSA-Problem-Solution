class Solution {
    public int maxDepth(String s) {
        int count = 0, open = 0;
        for(int i = 0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch == '('){
                open++;
            }
            if(ch == ')'){
                open--;
            }
            count = Math.max(count,open);
        }
        return count;
    }
}
