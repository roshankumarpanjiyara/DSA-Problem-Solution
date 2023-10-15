class Solution {
    int t[][];
    int MOD = 1000000007;
    int n;
    int solve(int i, int steps, int arrLen){
        if(i < 0 || i >= n){
            return 0;
        }
        if(steps == 0){
            if(i == 0){
                return 1;
            }else{
                return 0;
            }
        }

        if(t[i][steps] != -1){
            return t[i][steps];
        }

        int result = solve(i, steps-1, arrLen) % MOD;
        result = (result + solve(i+1, steps-1, arrLen)) % MOD;
        result = (result + solve(i-1, steps-1, arrLen)) % MOD;

        return t[i][steps] = result % MOD;
    }
    public int numWays(int steps, int arrLen) {
        n = Math.min(steps, arrLen);
        t = new int[501][501];
        for (int[] row : t) 
            Arrays.fill(row, -1);
        return solve(0, steps, arrLen);
    }
}
