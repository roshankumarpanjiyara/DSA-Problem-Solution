class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> vt;
        int n = words.size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j){
                    continue;
                }
                if(words[j].find(words[i]) != string::npos){
                    vt.push_back(words[i]);
                    break;
                }
            }
        }

        return vt;
    }
};
