class Solution {
    private int getNum(int n){
        int total = 0;
        while(n>0){
            int d = n % 10;
            total += d*d;
            n = n/10;
        }
        return total;
    }
    public boolean isHappy(int n) {
        HashSet<Integer> check = new HashSet<>();
        while(n != 1 && !check.contains(n)){
            check.add(n);
            n = getNum(n);
        }
        return n==1;
    }
}
