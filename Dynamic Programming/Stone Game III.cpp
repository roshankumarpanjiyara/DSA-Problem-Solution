class Solution {
public:
    // int n;
    // vector<int> dp;
    // int solve(vector<int>& stone, int i){
    //     if(i >= n){
    //         return 0;
    //     }

    //     if(dp[i] != -1){
    //         return dp[i];
    //     }

    //     int res = stone[i] - solve(stone, i+1);

    //     if(i+1 < n){
    //         res = max(res, (stone[i]+stone[i+1])- solve(stone, i+2));
    //     }
    //     if(i+2 < n){
    //         res = max(res, (stone[i] + stone[i+1] + stone[i+2] )- solve(stone, i+3));
    //     }

    //     return dp[i] = res;
    // }
    // string stoneGameIII(vector<int>& stoneValue) {
    //     n = stoneValue.size();

    //     dp.resize(n+1, -1);

    //     int res = solve(stoneValue, 0);

    //     if(res > 0){
    //         return "Alice";
    //     }else if(res < 0){
    //         return "Bob";
    //     }else{
    //         return "Tie";
    //     }
    // }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // vector<int> dp(n+1);

        int a = 0;
        int b = 0;
        int c = 0;

        for(int i = n-1; i>= 0;i--){
            int result = INT_MIN;

            result = max(result, stoneValue[i] - a);
            // dp[i] = stoneValue[i]-dp[i+1];

            if(i+2 <= n){
                // dp[i] = stoneValue[i] + stoneValue[i+1] - dp[i+2];
                result = max(result, stoneValue[i] + stoneValue[i+1] - b);
            }

            if(i+3 <= n){
                // dp[i] = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3];
                result = max(result, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - c);
            }

            c = b;
            b = a;
            a = result;
        }

        // int res = dp[0];
        int res = a;

        if(res > 0){
            return "Alice";
        }else if(res < 0){
            return "Bob";
        }else{
            return "Tie";
        }
    }
};
