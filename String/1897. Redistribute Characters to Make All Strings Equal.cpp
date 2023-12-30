class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int freq[26];
        memset(freq, 0, sizeof(freq));

        if(words.size() == 1){
            return true;
        }

        for(int i = 0;i<words.size();i++){
            for(char c : words[i]){
                freq[c - 'a']++;
            }
        }

        for(int i : freq){
            if(i % words.size() != 0){
                return false;
            }

            // cout<<i<<" ";
        }

        return true;
    }
};
