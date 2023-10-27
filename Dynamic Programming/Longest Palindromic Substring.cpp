class Solution {
public:
    int t[1001][1001];
    int checkPalin(string &s, int i, int j){
        if(i >= j){
            return 1;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(s[i] == s[j]){
            return t[i][j] = checkPalin(s, i+1, j-1);
        }
        return t[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        int start = -1;
        memset(t, -1, sizeof(t));

        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){

                if(checkPalin(s, i, j) == 1){
                    if(maxLen < (j - i + 1)){
                        maxLen = j - i + 1;
                        start = i;
                    }
                }

            }
        }

        return s.substr(start, maxLen);
    }
};
