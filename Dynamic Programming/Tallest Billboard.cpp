class Solution {
public:
    int t[21][10003];
    int solve(vector<int>& rods, int i, int diff){
        if(i >= rods.size()){
            if(diff == 0){
                return 0;
            }
            return INT_MIN;
        }

        if(t[i][diff + 5000] != -1){
            return t[i][diff + 5000];
        }

        int noRod = solve(rods, i+1, diff);
        int addTol1 = rods[i] + solve(rods, i+1, diff + rods[i]);
        int addTol2 = rods[i] + solve(rods, i+1, diff - rods[i]);

        return t[i][diff + 5000] = max({noRod, addTol1, addTol2});
    }
    int tallestBillboard(vector<int>& rods) {
        memset(t, -1, sizeof(t));
        return solve(rods, 0, 0)/2;
    }
};
