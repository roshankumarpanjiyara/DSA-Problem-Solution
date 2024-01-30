class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int ans = 0;

        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push(tokens[i]);
            }else{
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();

                if(tokens[i] == "+"){
                    ans = b + a;
                }else if(tokens[i] == "-"){
                    ans = b - a;
                }else if(tokens[i] == "*"){
                    ans = b * a;
                }else{
                    ans = b / a;
                }

                st.push(to_string(ans));
            }
        }
        return stoi(st.top());
    }
};
