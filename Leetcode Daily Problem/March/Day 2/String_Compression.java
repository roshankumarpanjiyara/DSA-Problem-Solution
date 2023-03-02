class Solution {
    public int compress(char[] chars) {
        int count = 1;
        int j = 0;
        if(chars.length == 1){
            return 1;
        }
        for(int i = 1;i<=chars.length;i++){
            count = 1;
            while(i<chars.length && chars[i] == chars[i-1]){
                count++;
                i++;
            }
            chars[j++] = chars[i-1];
            if(count > 1){
                String s = Integer.toString(count);
                for(int k = 0;k<s.length();k++){
                    chars[j++] = s.charAt(k);
                }
            }
        }
        return j;
    }
}
