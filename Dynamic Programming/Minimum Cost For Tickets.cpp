class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last_day = days[days.size()-1];
        int t[last_day+1];
        set<int> st(days.begin(),days.end());

        t[0] = 0;
        for(int i = 1;i<=last_day;i++){
            if(st.find(i)==st.end()){
                t[i] = t[i-1];
                continue;
            }
            t[i] = INT_MAX;
            int pass_1 = costs[0] + t[max(i-1,0)];
            int pass_7 = costs[1] + t[max(i-7,0)];
            int pass_30 = costs[2] + t[max(i-30,0)];
            t[i] = min({pass_1, pass_7, pass_30});
        }
        return t[last_day];
    }
};
