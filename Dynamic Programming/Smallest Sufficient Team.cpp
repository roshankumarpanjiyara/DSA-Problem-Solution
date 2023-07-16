class Solution {
public:
    int n, m, target_mask;
    vector<int> result;
    unordered_map<string, int> dp;
    void solve(vector<int>& people_skill, int idx, vector<int>& temp, int mask){
        if(idx == people_skill.size()){
            if(mask == target_mask){
                if(result.size() == 0 || result.size() >= temp.size()){
                    result = temp;
                }
            }
            return;
        }
        if(result.size() != 0 && result.size() <= temp.size()){
            return;
        }

        string key = to_string(idx)+"_"+to_string(mask);
        if(dp.find(key) != dp.end()){
            if(dp[key] <= temp.size()){
                return;
            }
        }

        //skip
        solve(people_skill, idx+1, temp, mask);
        //take
        if((mask | people_skill[idx]) != mask){
            temp.push_back(idx);
            solve(people_skill, idx + 1, temp, (mask | people_skill[idx]));
            temp.pop_back();
            dp[key] = temp.size() != 0 ? temp.size() : -1;
        }
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();
        m = people.size();

        unordered_map<string, int> skills;
        for(int i = 0;i<n;i++){
            skills[req_skills[i]] = i;
        }

        vector<int> people_skill;
        for(auto &v : people){
            int skill_bit = 0;
            for(auto &skill : v){
                skill_bit = skill_bit | (1 << skills[skill]);
            }
            people_skill.push_back(skill_bit);
        }

        vector<int> temp;
        target_mask = pow(2, n) - 1;
        solve(people_skill, 0, temp, 0);
        return result;
    }
};
