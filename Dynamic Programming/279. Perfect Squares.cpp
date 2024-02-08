//bottom up

class Solution {
    public int numSquares(int n) {
        int t[] = new int[n+1];
        Arrays.fill(t, Integer.MAX_VALUE);
        t[0] = 0;
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j*j <= i; j++){
                t[i] = Math.min(t[i],1 + t[i - (j*j)]);
            }
        }

        return t[n];
    }
}

//recursion + memoization

class Solution {
public:
    int t[10001];
    int solve(int n){
        if(n == 0){
            return 0;
        }

        if(t[n] != -1){
            return t[n];
        }

        int minCount = INT_MAX;
        for(int i = 1;i*i<=n;i++){
            minCount = min(minCount, 1 + solve(n - i*i));
        }

        return t[n] = minCount;
    }
    int numSquares(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};
