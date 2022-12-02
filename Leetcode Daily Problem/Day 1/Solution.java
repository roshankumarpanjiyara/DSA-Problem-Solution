class Solution {
    public boolean halvesAreAlike(String s) {
        s = s.toUpperCase();
        int c = 0;
        for(int i = 0;i<s.length()/2;i++){
            char ch = s.charAt(i);
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                c++;
            }
        }
        for(int i = s.length()/2;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                c--;
            }
        }
        if(c == 0){
            return true;
        }else{
            return false;
        }
    }
}
