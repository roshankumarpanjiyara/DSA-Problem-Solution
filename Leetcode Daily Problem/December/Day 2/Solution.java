class Solution {
    public boolean closeStrings(String word1, String word2) {
        if(word1.length() != word2.length()){
            return false;
        }
        int[] s1 = new int[26];
        int[] s2 = new int[26];
        int[] s3 = new int[26];
        int[] s4 = new int[26];

        for(int i = 0;i<word1.length();i++){
            char ch = word1.charAt(i);
            s1[ch - 'a']++;
            s3[ch - 'a'] = 1;
        }

        for(int i = 0;i<word2.length();i++){
            char ch = word2.charAt(i);
            s2[ch - 'a']++;
            s4[ch - 'a'] = 1;
        }

        Arrays.sort(s1);
        Arrays.sort(s2);

        return (Arrays.equals(s1,s2) && Arrays.equals(s3,s4));
    }
}
