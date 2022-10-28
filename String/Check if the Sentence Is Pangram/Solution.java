class Solution {
    public boolean checkIfPangram(String sentence) {
      //approach 1
        int[] charac = new int[26];
        for(int i = 0;i<sentence.length();i++){
            char ch = sentence.charAt(i);
            charac[ch-97]++;
        }
        for(int i = 0;i<26;i++){
            if(charac[i] == 0){
                return false;
            }
        }
        return true;
        
      //approach 2
        for(int i = 0;i<26;i++){
            char ch = (char)('a'+i);
            if(sentence.indexOf(ch) == -1){
                return false;
            }
        }
        return true;
    }
}
