class Solution {
    // public static int palindrome(String s, int i, int j){
    //     while(i<j){
    //         if(s.charAt(i) != s.charAt(j)){
    //             return 0;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return 1;
    // }
    public int countSubstrings(String s) {
        int count = 0;
        // for(int i = 0;i<s.length();i++){
        //     for(int j = i;j<s.length();j++){
        //         count += palindrome(s,i,j);
        //     }
        // }

        boolean dp[][] = new boolean[s.length()][s.length()];
        for(int g = 0;g<s.length();g++){
            for(int i = 0,j = g;j<dp.length;j++,i++){
                if(g == 0){
                    dp[i][j] = true;
                }else if(g == 1){
                    if(s.charAt(i) == s.charAt(j)){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    if(s.charAt(i) == s.charAt(j) && dp[i+1][j-1] == true){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
                if(dp[i][j] == true){
                    count++;
                }
            }
        }
        return count;
    }
}
