class Solution {
public:
    int n;
    int t[11][301];
    int solve(int idx, vector<int>& jd, int d){
        if(d == 1){
            int maxJob = jd[idx];
            for(int i = idx;i<n;i++){
                maxJob = max(maxJob, jd[i]);
            }
            return maxJob;
        }

        if(t[d][idx] != -1){
            return t[d][idx];
        }

        int maxJob = jd[idx];
        int res = INT_MAX;
        for(int i = idx;i<=n-d;i++){
            maxJob = max(maxJob, jd[i]);
            int sum = maxJob + solve(i + 1, jd, d - 1);
            res = min(res, sum);
        }

        return t[d][idx] = res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        memset(t, -1, sizeof(t));
        if(n < d){
            return -1;
        }
        return solve(0, jobDifficulty, d); 
    }
};
