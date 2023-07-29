class Solution {
public:
    vector<vector<int>> serve = {{100,0}, {75,25}, {50,50}, {25,75}};
    vector<vector<double>> t;
    double solve(int A, int B){
        if(A <= 0 && B <= 0){
            return 0.5;
        }
        if(A <= 0){
            return 1.0;
        }
        if(B <= 0){
            return 0.0;
        }

        if(t[A][B] != -1.0){
            return t[A][B];
        }

        double prob = 0.0;
        for(auto i : serve){
            int A_taken = i[0];
            int B_taken = i[1];

            prob += solve(A - A_taken, B - B_taken);
        }

        return t[A][B] = 0.25*prob;
    }
    double soupServings(int n) {
        if(n >= 4000){
            return 1;
        }
        t.resize(n+1, vector<double>(n+1, -1.0));
        return solve(n, n);
    }
};
