class Solution {
    public int minimumSwap(String s1, String s2) {
        if(s1.length() != s2.length()){
            return -1;
        }
        int xy = 0, yx = 0;
        for(int i = 0;i<s1.length();i++){
            char ch1 = s1.charAt(i);
            char ch2 = s2.charAt(i);

            if(ch1 == 'x' && ch2 == 'y'){
                xy++;
            }
            if(ch1 == 'y' && ch2 == 'x'){
                yx++;
            }
        }
        if((xy+yx)%2 == 1){
            return -1;
        }else{
            return xy/2 + xy%2 + yx/2 + yx%2;
        }
    }
}
