class Solution {
public:
    int t[501][501];
    int solve(int i, int walls, vector<int>& cost, vector<int>& time){
        if(walls <= 0){
            return 0;
        }

        if(i >= cost.size()){
            return 1e9;
        }

        if(t[i][walls] != -1){
            return t[i][walls];
        }

        int paint = cost[i] + solve(i + 1, walls - 1 - time[i], cost, time);
        int dont_paint = solve(i + 1, walls, cost, time);

        return t[i][walls] = min(paint, dont_paint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(t, -1, sizeof(t));
        return solve(0, n, cost, time);
    }
};
