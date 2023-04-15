class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string token = "";
        stringstream ss(path);
        while(getline(ss, token, '/')){
            if(token == "." || token == ""){
                continue;
            }
            if(token != ".."){
                st.push_back(token);
            }else if(!st.empty()){
                st.pop_back();
            }
        }

        if(st.empty()){
            return "/";
        }

        string res="";
        for(auto &tk: st){
            res += "/" + tk;
        }
        return res;
    }
};
