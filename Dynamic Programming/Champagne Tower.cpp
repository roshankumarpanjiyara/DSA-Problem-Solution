class Solution {
public:
    double t[101][101];
    double solve(int i,int j, int poured){
        if(i < 0 || j < 0 || i < j){
            return 0.0;
        }
        if(i == 0 && j == 0){
            return poured;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        double left = (solve(i-1, j-1, poured)-1)/2.0;
        double right = (solve(i-1, j, poured)-1)/2.0;

        if(left < 0){
            left = 0.0;
        }

        if(right < 0){
            right = 0.0;
        }

        return t[i][j] = left + right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        // memset(t, -1, sizeof(t));
        for(int i = 0;i<101;i++){
            for(int j = 0;j<101;j++){
                t[i][j] = -1;
            }
        }
        return min(1.0, solve(query_row, query_glass, poured));
    }
};
