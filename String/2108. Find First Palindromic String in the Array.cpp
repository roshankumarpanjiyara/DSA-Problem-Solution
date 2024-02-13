class Solution {
public:
    bool palin(string s){
        int i = 0;
        int j = s.size()-1;

        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string s : words){
            if(palin(s)){
                return s;
            }
        }
        return "";
    }
};
