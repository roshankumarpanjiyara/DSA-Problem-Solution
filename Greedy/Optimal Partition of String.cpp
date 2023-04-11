class Solution {
public:
    int partitionString(string s) {
        // unordered_set<char> st;
        // int count = 0;
        // for(int i = 0;i<s.length();i++){
        //     if(st.find(s[i]) != st.end()){
        //         count++;
        //         st.clear();
        //     }
        //     st.insert(s[i]);
        // }
        // return count+1;


        vector<int> last_seen(26, -1);
        int count = 0;
        int curr_substring = 0;

        for(int i = 0;i<s.length();i++){
            if(last_seen[s[i] - 'a'] >= curr_substring){
                count++;
                curr_substring = i;
            }
            last_seen[s[i] - 'a'] = i;
        }
        return count+1;
    }
};
