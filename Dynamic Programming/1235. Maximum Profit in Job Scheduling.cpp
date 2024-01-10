class Solution {
public:
    int n;
    int t[50001];
    int getNextJob(vector<vector<int>>& arr, int l, int target){
        int r = n - 1;
        int res = n + 1;

        while(l <= r){
            int mid = l + (r - l)/2;
            if(arr[mid][0] >= target){
                res = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return res;
    }
    int solve(vector<vector<int>>& arr, int i){
        if(i >= n){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int nextJob = getNextJob(arr, i + 1, arr[i][1]);
        int taken = arr[i][2] + solve(arr, nextJob);
        int not_taken = solve(arr, i + 1);

        return t[i] = max(taken, not_taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(t, -1, sizeof(t));
        vector<vector<int>> arr(n, vector<int>(3, 0));

        for(int i = 0;i<n;i++){
            arr[i] = {startTime[i], endTime[i], profit[i]};
        }

        auto comp = [&](auto& vec1, auto& vec2){
            return vec1[0] <= vec2[0];
        };
        sort(begin(arr), end(arr), comp);

        return solve(arr, 0);
    }
};
