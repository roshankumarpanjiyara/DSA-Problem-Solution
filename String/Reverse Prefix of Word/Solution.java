class Solution {
    public String reversePrefix(String word, char ch) {
        int n = word.indexOf(ch);
        if(n == -1){
            return word;
        }
        String ans = "";
        for(int i = 0;i<=n;i++){
            ans = word.charAt(i) + ans;
        }
        return ans.concat(word.substring(n+1,word.length()));
    }
}
