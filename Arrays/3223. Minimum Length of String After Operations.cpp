class Solution {
public:
    int minimumLength(string s) {
        int count = 0;
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch-'a']++;
        }

        for(int i = 0;i<26;i++){
            if(freq[i] == 0){
                continue;
            }
            if(freq[i] % 2 == 0){
                count += 2;
            }else{
                count += 1;
            }
            cout<<freq[i]<<endl;
        }

        return count;
    }
};
