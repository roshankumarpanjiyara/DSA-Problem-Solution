class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = limit+1;
        vector<int> ans;
        unordered_map<int, int> mp_balls;
        unordered_map<int, int> mp_count;

        for(vector<int> &vt: queries){
            int ball = vt[0];
            int color = vt[1];
            if(mp_balls.find(ball) != mp_balls.end()){
                mp_count[mp_balls[ball]]--;
                if(mp_count[mp_balls[ball]] == 0){
                    mp_count.erase(mp_balls[ball]);
                }
            }
            mp_balls[ball] = color;
            mp_count[color]++;

            ans.push_back(mp_count.size());
        }

        return ans;
    }
};
