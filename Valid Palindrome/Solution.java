class Solution {
    public boolean isPalindrome(String s) {
      //Mehod 1
        String s1 = "";
        String s2 = "";
        s = s.toLowerCase();
        for(int i = 0;i<s.length();i++){
            char ch = s.charAt(i);
            if((ch >= 97 && ch <= 122) || (ch >=48 && ch<=57)){
                s1 = s1 + ch;
                s2 = ch + s2;
            }
        }
        if(s1.equals(s2)){
            return true;
        }else{
            return false;
        }
      //Method 2
        String actual = s.replaceAll("[^A-Za-z0-9]","").toLowerCase();
        String reverse = new StringBuffer(actual).reverse().toString();
        return actual.equals(reverse);
    }
}
