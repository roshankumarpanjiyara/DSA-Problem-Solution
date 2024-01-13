class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq_s(26, 0);

        for(char c : s){
            freq_s[c - 'a']++;
        }

        int sum = s.size();
        for(char c : t){
            if(freq_s[c - 'a'] != 0){
                freq_s[c - 'a']--;
                sum--;
            }
        }

        return sum;
    }
};
