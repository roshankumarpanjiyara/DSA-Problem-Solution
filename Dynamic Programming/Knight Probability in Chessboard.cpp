class Solution {
public:
    int N;
    unordered_map<string, double> mp;
    vector<vector<int>> directions = {{-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {2, 1}, {2, -1}, {-1, -2}};
    double solve(int row, int col,int k){
        if(row < 0 || row >= N || col < 0 || col >= N){
            return 0;
        }
        if(k == 0){
            return 1;
        }
        string key = to_string(row)+"_"+to_string(col)+"_"+to_string(k);
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
        double result = 0;
        for(auto dir : directions){
            int nrow = row + dir[0];
            int ncol = col + dir[1];
            result += solve(nrow, ncol, k-1);
        }
        return mp[key] = (double)(result/8);
    }
    double knightProbability(int n, int k, int row, int column) {
        N = n;
        mp.clear();
        return solve(row, column, k);
    }
};
