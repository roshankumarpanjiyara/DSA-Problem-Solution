class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> vt(n, 0);

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }

            if(st.empty()){
                vt[i] = 0;
            }else{
                vt[i] = abs(i - st.top().second);
            }

            st.push({temperatures[i], i});
        }

        return vt;
    }
};
