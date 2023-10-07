class Solution {
public:
    int N, M, K;
    int MOD = 1e9+7;
    int t[52][52][102];
    int solve(int idx, int cost, int maxSoFar){
        if(idx == N){
            if(cost == K){
                return 1;
            }
            return 0;
        }
        if(t[idx][cost][maxSoFar] != -1){
            return t[idx][cost][maxSoFar];
        }
        int result = 0;
        for(int i = 1;i<=M;i++){
            if(i > maxSoFar){
                result = (result % MOD + solve(idx+1, cost+1, i))%MOD; 
            }else{
                result = (result % MOD + solve(idx+1, cost, maxSoFar))%MOD; 
            }
        }
        return t[idx][cost][maxSoFar] = result % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t, -1, sizeof(t));

        return solve(0, 0, 0);
    }
};
