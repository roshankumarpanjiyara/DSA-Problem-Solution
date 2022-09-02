class Solution {
    public static int maxProfit(int n, int[] price) {
        // code here
        int fb = Integer.MIN_VALUE;
        int fs = 0;
        int sb = Integer.MIN_VALUE;
        int ss = 0;
        
        for(int i = 0;i<n;i++){
            fb = Math.max(fb,-price[i]);
            fs = Math.max(fs,fb+price[i]);
            sb = Math.max(sb,fs-price[i]);
            ss = Math.max(ss,sb+price[i]);
        }
        return ss;
    }
}
   
