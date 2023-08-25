class Solution {
public:
    int n, m, l;
    int t[101][101];
    bool solve(string s1, int i, string s2, int j, string s3){
        if(i == n && j == m && i+j == l){
            return true;
        }
        if(i+j >= l){
            return false;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        bool result;
        if(i < n && i+j < l && s1[i] == s3[i+j]){
            result = solve(s1, i + 1, s2, j, s3);
        }
        if(result == true){
            return t[i][j] = true;
        }
        if(j < m && i+j < l && s2[j] == s3[i+j]){
            result = solve(s1, i, s2, j + 1, s3);
        }
        return t[i][j] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length();
        m = s2.length();
        l = s3.length();
        if(n + m != l){
            return false;
        }
        memset(t, -1, sizeof(t));
        return solve(s1, 0, s2, 0, s3);
    }
};
