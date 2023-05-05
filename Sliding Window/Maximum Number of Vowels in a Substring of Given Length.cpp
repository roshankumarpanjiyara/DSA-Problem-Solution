class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        int maxV = INT_MIN;

        for(int i = 0;i<s.length();i++){
            while(j<s.length() && j-i+1 <= k){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                    count++;
                }
                j++;
            }
            maxV = max(maxV, count);
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count--;
            }
        }
        return maxV;
    }
};
