class Solution {
public:
    int t[301][5001];
    int solve(int i, vector<int>& coins, int amount){
        if(amount == 0){
            return 1;
        }
        if(i >= coins.size()){
            return 0;
        }

        if(t[i][amount] != -1){
            return t[i][amount];
        }

        if(coins[i] > amount){//skip if amount is less
            return t[i][amount] = solve(i+1, coins, amount);
        }

        int skip = solve(i+1, coins, amount);
        int take = solve(i, coins, amount - coins[i]);

        return t[i][amount] = skip + take;
    }
    int change(int amount, vector<int>& coins) {
        memset(t, -1, sizeof(t));
        return solve(0, coins, amount);
    }
};
