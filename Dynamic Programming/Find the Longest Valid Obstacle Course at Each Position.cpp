class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> dp;
        vector<int> result(n);

        for(int i = 0;i<n;i++){
            int idx = upper_bound(begin(dp), end(dp), obstacles[i]) - begin(dp);

            if(idx == dp.size()){
                dp.push_back(obstacles[i]);
            }else{
                dp[idx] = obstacles[i];
            }
            result[i] = idx+1;
        }

        return result;
    }
};
