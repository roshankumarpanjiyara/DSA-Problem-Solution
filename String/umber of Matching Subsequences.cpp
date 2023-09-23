class Solution {
public:
    map<char, vector<int>> mp;
    bool isSub(string word1, string word2){
        int n = word1.length();
        int m = word2.length();

        int prev = -1;
        for(int i = 0;i<m;i++){
            char ch = word2[i];

            if(mp.find(ch) == mp.end()){
                return false;
            }
            auto it = upper_bound(mp[ch].begin(), mp[ch].end(), prev);
            if(it == mp[ch].end()){
                return false;
            }

            prev = *it;
        }

        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        for(int i = 0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }

        int c = 0;
        for(string word : words){
            if(isSub(s, word)){
                c++;
            }
        }

        return c;
    }
};
