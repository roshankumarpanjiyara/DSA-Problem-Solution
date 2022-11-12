class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> check = new HashMap<>();
        check.put('I',1);
        check.put('V',5);
        check.put('X',10);
        check.put('L',50);
        check.put('C',100);
        check.put('D',500);
        check.put('M',1000);

        int ans = check.get(s.charAt(s.length()-1));
        for(int i = s.length()-2;i>=0;i--){
            if(check.get(s.charAt(i))<check.get(s.charAt(i+1))){
                ans -= check.get(s.charAt(i));
            }else{
                ans += check.get(s.charAt(i));
            }
        }
        return ans;
    }
}
