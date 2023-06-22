class Solution {
public:
    int t[500001][2];
    int solve(vector<int>& prices, int day, int n, bool buy, int fee){
        if(day >= n){
            return 0;
        }
        int profit = 0;
        if(t[day][buy] != -1){
            return t[day][buy];
        }
        if(buy){
            int take = solve(prices, day+1, n, false, fee) - prices[day];
            int notTake = solve(prices, day+1, n, true, fee);
            profit = max({profit, take, notTake});
        }else{
            int sell = prices[day] + solve(prices, day+1, n, true, fee) - fee;
            int notSell = solve(prices, day+1, n, false, fee);
            profit = max({profit, sell, notSell});
        }
        return t[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        bool buy = true;
        memset(t, -1, sizeof(t));

        return solve(prices, 0, n, buy, fee);
    }
};
