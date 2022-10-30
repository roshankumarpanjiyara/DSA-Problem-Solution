class Solution {
    public int[] shortestToChar(String s, char c) {
      //approach 1
        int count = 0;
        boolean first = false;
        int[] ans = new int[s.length()];
        for(int i = 0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch == c){
                count = i;
                ans[i] = 0;
                first =  true;
            }else{
                if(first == false){
                    ans[i] = -1;
                }else{
                    ans[i] = Math.abs(count-i);   
                }
            }
        }
        // System.out.println(Arrays.toString(ans));
        count = 0;
        for(int i = s.length()-1;i>=0;i--){
            char ch = s.charAt(i);
            if(ch == c){
                count = i;
                ans[i] = 0;
            }else{
                if(ans[i] == -1){
                    ans[i] = Math.abs(count-i);
                }else{
                    ans[i] = Math.min(ans[i],Math.abs(count-i));   
                }
            }
        }
        // System.out.println(Arrays.toString(ans));
        return ans;
        
      //approach 2
        int[] ans = new int[s.length()];
        for(int i = 0;i<s.length();i++){
             
            int left = s.substring(0,i).lastIndexOf(c);
            int right = s.substring(i).indexOf(c);
            
            if(left>-1 && right>-1){
                ans[i] = Math.min(i-left,right);
            }else if(left>-1){
                ans[i] = i-left;
            }else{
                ans[i] = right;
            }
        }
        return ans;
    }
}
