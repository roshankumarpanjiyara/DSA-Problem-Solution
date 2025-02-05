class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        vector<int> vt;

        for(int i = 0;i<s1.length();i++){
            if(s1[i] != s2[i]){
                vt.push_back(i);
            }
        }

        if(vt.size() == 0){//equal string
            return true;
        }

        if(vt.size() == 2){
            if(s1[vt[0]] == s2[vt[1]] && s1[vt[1]] == s2[vt[0]]){
                return true;
            }
        }

        return false;

    }
};
