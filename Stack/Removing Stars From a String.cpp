class Solution {
public:
    string removeStars(string s) {
        //approach 1

        // string ans;
        // for(int i = 0;i<s.length();i++){
        //     char ch = s[i];
        //     if(ch == '*'){
        //         ans.pop_back();
        //     }else{
        //         ans += ch;
        //     }
        // }
        // return ans;

        //approach 2

        // stack<char> st;
        // for(int i = 0;i<s.length();i++){
        //     if(s[i] == '*'){
        //         st.pop();
        //     }else{
        //         st.push(s[i]);
        //     }
        // }
        // string result = "";
        
        // while(!st.empty()) {
        //     result.push_back(st.top());
        //     st.pop();
        // }
        
        // reverse(begin(result), end(result));
        // return result;

        //approach 3
        int n = s.length();
        vector<char> vec(n);
        int j = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '*'){
                j--;
            }else{
                vec[j++] = s[i];
            }
        }
        string res;
        for(int k = 0;k<=j-1;k++){
            res.push_back(vec[k]);
        }
        return res;
    }
};
