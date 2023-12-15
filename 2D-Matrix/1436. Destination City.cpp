class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        for(int i = 0;i<paths.size();i++){
            string dest = paths[i][1];
            bool flag = true;

            for(int j = 0;j<paths.size();j++){
                if(paths[j][0] == dest){
                    flag = false; 
                }
            }

            if(flag){
                return dest;
            }
        }

        return "";
    }
};
