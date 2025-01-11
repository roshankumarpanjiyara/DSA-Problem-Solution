class Solution {
public:
    bool isSubset(vector<int>& freq, int temp[]){
        for(int i = 0;i<26;i++){
            if(freq[i] > temp[i]){
                return false;
            }
        }

        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> freq_words2(26, 0);
        for(string s : words2){
            int temp[26] = {0};

            for(char ch : s){
                temp[ch - 'a']++;
                freq_words2[ch - 'a'] = max(temp[ch- 'a'], freq_words2[ch - 'a']);
            }
        }

        for(string s : words1){
            int temp[26] = {0};

            for(char ch : s){
                temp[ch - 'a']++;
            }

            if(isSubset(freq_words2, temp) == true){
                res.push_back(s);
            }
        }

        return res;

    }
};
