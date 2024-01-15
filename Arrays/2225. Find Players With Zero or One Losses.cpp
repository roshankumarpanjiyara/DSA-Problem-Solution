class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int, int> freq;

        for(auto it : matches){
            int win = it[0];
            int lose = it[1];

            if(!freq.count(win)){
                freq[win] = 0;
            }
            freq[lose]++;
        }

        for(auto entry : freq){
            if(entry.second == 0){
                ans[0].push_back(entry.first);
            }
            if(entry.second == 1){
                ans[1].push_back(entry.first);
            }
        }

        return ans; 
    }
};
