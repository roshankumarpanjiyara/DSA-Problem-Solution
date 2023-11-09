class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        int curr = 0;
        int MOD = 1e9+7;

        for(int i = 0;i<s.length();i++){
            if(i == 0 || s[i] == s[i-1]){
                curr++;
            }else{
                curr = 1;
            }
            ans = (ans%MOD + curr%MOD)%MOD;
        }

        return ans;
    }
};
