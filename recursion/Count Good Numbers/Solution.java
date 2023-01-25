class Solution {
    public int mod = 1000000007;

    public long power(long x, long y){
        long res = 1;
        x = x % mod;
        if(x == 0){
            return 0;
        }
        while(y > 0){
            if(y % 2 != 0){
                res = (res*x) % mod;
            }
            y = y>>1;
            x = (x*x) % mod;
        }
        return res;
    }

    public int countGoodNumbers(long n) {
        long oddCount = n/2;
        long evenCount = n/2 + n%2;
        long ans = ((power((long)5,evenCount) % mod) * (power((long)4,oddCount) % mod)) % mod;
        return (int)(ans);
    }
}
