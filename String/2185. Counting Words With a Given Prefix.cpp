class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int len_pref = pref.length();
        for(string s: words){
            if(pref == s.substr(0, len_pref)){
                count++;
            }
        }
        return count++;
    }
};
