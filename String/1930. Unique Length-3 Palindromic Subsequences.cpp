class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> idx(26, {-1, -1});

        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            int idx_ch = ch - 'a';

            if(idx[idx_ch].first == -1){
                idx[idx_ch].first = i;
            }
            idx[idx_ch].second = i;
        }

        int ans = 0;

        for(int i = 0;i<26;i++){
            int left_idx = idx[i].first;
            int right_idx = idx[i].second;

            if(left_idx == -1){
                continue;
            }

            unordered_set<char> between;
            for(int mid = left_idx+1;mid <= right_idx-1;mid++){
                between.insert(s[mid]);
            }

            ans += between.size();
        }

        return ans;
    }
};
