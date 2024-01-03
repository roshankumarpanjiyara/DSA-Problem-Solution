class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> vt;

        for(int i = 0;i<bank.size();i++){
            int count = 0;
            for(char c : bank[i]){
                if(c == '1'){
                    count++;
                }
            }
            if(count > 0){
                vt.push_back(count);
            }
        }

        if(vt.size() == 0){
            return 0;
        }
        
        int ans = 0;

        for(int i = 0;i<vt.size()-1;i++){
            ans += (vt[i]*vt[i+1]);
        }

        return ans;
    }
};
