// leetcode
class Solution {
    public String reverseWords(String s) {
        StringBuilder ans = new StringBuilder("");
        int i = s.length()-1;
        while(i>=0){
            while(i>=0 && s.charAt(i) == ' '){
                i--;
            }
            int j = i;
            if(i<0){
                break;
            }
            while(i>=0 && s.charAt(i) != ' '){
                i--;
            }
            if(ans.isEmpty()){
                ans = ans.append(s.substring(i+1,j+1));
            }else{
                ans = ans.append(" " + s.substring(i+1,j+1));
            }
        }
        return ans.toString();
        
    }
}

// gfg

class Solution 
{
    //Function to reverse words in a given string.
    String reverseWords(String S)
    {
        // code here 
        String []words = S.split("[.]");
        Collections.reverse(Arrays.asList(words));
        return String.join(".",words);
    }
}
