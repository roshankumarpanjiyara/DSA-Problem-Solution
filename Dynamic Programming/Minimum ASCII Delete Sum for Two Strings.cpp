class Solution {
public:
    int n, m;
    int t[1005][1005];
    int solve(int i, int j, string &s1, string &s2){
        if(i >= n && j >= m){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(i >= n){
            return t[i][j] = s2[j] + solve(i, j+1, s1, s2);
        }else if(j >= m){
            return t[i][j] = s1[i] + solve(i+1, j, s1, s2);
        }

        if(s1[i] == s2[j]){
            return t[i][j] = solve(i+1, j+1, s1, s2);
        }else{
            int del_i = s1[i] + solve(i+1, j, s1, s2);
            int del_j = s2[j] + solve(i, j+1, s1, s2);

            return t[i][j] = min(del_i, del_j);
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, s1, s2);
    }
};
