class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string s : details){
            int t = s[11]-'0';
            int z = s[12]-'0';

            if((t*10 + z) > 60){
                count++;
            }
            cout<<t*10 + z<<" "<<s.length()<<endl;
        }
        return count;
    }
};
