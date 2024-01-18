class Solution {
public:
    int t[46];
    int solve(int n){
        if(n <= 0){
            return 0;
        }
        if(t[n] != -1){
            return t[n];
        }
        if(n == 1 || n == 2){
            return n;
        }

        int take_1 = solve(n-1);
        int take_2 = solve(n-2);

        return t[n] = take_1 + take_2;
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};
