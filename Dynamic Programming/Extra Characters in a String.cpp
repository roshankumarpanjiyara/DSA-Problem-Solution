class Solution {
public:
    int n;
    int t[55];
    int solve(int idx, unordered_set<string>& st, string s){
        if(idx >= n){
            return 0;
        }
        string curString = "";
        int minExtra = n;

        if(t[idx] != -1){
            return t[idx];
        }

        for(int i = idx;i<n;i++){
            curString.push_back(s[i]);
            int curExtra = 0;
            if(st.find(curString) == st.end()){
                curExtra = curString.length();
            }
            int remianingExtra = solve(i+1, st, s);
            minExtra = min(minExtra, curExtra + remianingExtra);
        }
        return t[idx] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        memset(t, -1, sizeof(t));
        unordered_set<string> st(begin(dictionary), end(dictionary));
        return solve(0, st, s);
    }
};
