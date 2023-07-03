class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }

        if(s == goal){
            int freq[26];
            memset(freq, 0, sizeof(freq));

            for(int i = 0;i<s.length();i++){
                freq[s[i] - 'a']++;
                if(freq[s[i] - 'a'] == 2){
                    return true;
                }
            }

            return false;
        }

        int firstIdx = -1;
        int secondIdx = -1;

        for(int i = 0;i<s.length();i++){
            if(s[i] != goal[i]){
                if(firstIdx == -1){
                    firstIdx = i;
                }else if(secondIdx == -1){
                    secondIdx = i;
                }else{
                    return false;
                }
            }
        }
        if(secondIdx == -1){
            return false;
        }

        return s[firstIdx] == goal[secondIdx] && s[secondIdx] == goal[firstIdx];
    }
};
