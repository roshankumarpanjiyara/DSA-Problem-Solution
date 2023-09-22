class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        int i = 0;
        int j = 0;

        while(j < m){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }

        return i == n;
    }
};
