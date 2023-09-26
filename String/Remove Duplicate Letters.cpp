class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string ans;
        int last[26] = {0};
        bool taken[26] = {false};

        for(int i = 0;i<n;i++){
            last[s[i]-'a'] = i;
        }

        for(int i = 0;i<n;i++){
            char ch = s[i];
            if(taken[ch-'a'] == true){
                continue;
            }
            while(ans.length() > 0 && ans.back() > ch && last[ans.back()-'a'] > i){
                taken[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            taken[ch-'a'] = true;
        }

        return ans;
    }
};
