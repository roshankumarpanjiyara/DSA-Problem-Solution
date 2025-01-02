class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int n = queries.size();
        vector<int> ans(n);
        vector<int> temp(words.size());
        int count = 0;

        for(int i = 0;i<words.size();i++){
            char startLetter = words[i][0];
            char endLetter = words[i][words[i].size()-1];

            if(words[i].size() == 1){
                if(st.find(startLetter) != st.end()){
                    count++;
                }
            }else{
                if(st.find(startLetter) != st.end() && st.find(endLetter) != st.end()){
                    count++;
                }
            }
            temp[i] = count;
        }
        for (int i: temp)
            cout << i << ' ';
        for(int i = 0;i<n;i++){
            int start = queries[i][0];
            int end = queries[i][1];

            ans[i] = temp[end] - (start == 0 ? 0 : temp[start - 1]);
        }

        return ans;
    }
};
