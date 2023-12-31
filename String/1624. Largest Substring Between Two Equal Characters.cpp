class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> vt(26, INT_MAX);
        int maxLen = -1;
        for(int i = 0;i<s.size();i++){
            if(vt[s[i] - 'a'] != INT_MAX){
                maxLen = max(maxLen, i - vt[s[i] - 'a'] - 1);
            }
            vt[s[i] - 'a'] = min(i, vt[s[i] - 'a']);
        }

        for(int i : vt){
            cout<<i<<" ";
        }
        return maxLen;
    }
};
