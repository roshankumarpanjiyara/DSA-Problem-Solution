class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int l = 1;l<=n/2;l++){
            if(n % l == 0){
                string pattern = "";
                int times = n / l;
                for(int i = 0;i<times;i++){
                    pattern += s.substr(0, l);
                }
                if(pattern == s){
                    return true;
                }
            }
        }
        return false;
    }
};
