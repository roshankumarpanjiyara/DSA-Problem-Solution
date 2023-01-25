class Solution {
    public int myAtoi(String s) {
        int i = 0, sign = 1, ans = 0;

        while(i<s.length() && s.charAt(i) == ' '){
            i++;
        }

        if(i>=s.length()){
            return 0;
        }

        if(s.charAt(i) == '+' || s.charAt(i) == '-'){
            sign = (s.charAt(i) == '+') ? +1 : -1;
            i++;
        }

        if(i>=s.length()){
            return 0;
        }

        while(i<s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9'){

            if(ans > Integer.MAX_VALUE/10 || (ans == Integer.MAX_VALUE/10 && s.charAt(i)-'0' > Integer.MAX_VALUE%10)){
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            ans = ans*10 + s.charAt(i)-'0';
            // System.out.println(i+" "+ans+" "+s.charAt(i)+" "+sign);
            i++;
        }

        return ans*sign;
        
    }
}
