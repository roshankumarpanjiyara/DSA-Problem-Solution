class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n == 1){
            return 0;
        }

        vector<int> t(n, 0);
        t[0] = 0;
        t[1] = max(prices[1] - prices[0], 0);

        for(int i = 2;i<n;i++){
            t[i] = t[i-1];
            for(int j = 0;j<=i-1;j++){
                int todayProfit = prices[i] - prices[j];
                int prevProfit = j >= 2 ? t[j-2] : 0;

                t[i] = max(t[i], todayProfit + prevProfit);
            }
        }

        return t[n-1];
    }
};
