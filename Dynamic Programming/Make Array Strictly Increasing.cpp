class Solution {
public:
    int n;
    map<pair<int, int>, int> dp;
    int solve(int i, vector<int>& arr1, vector<int>& arr2, int prev){
        if(i >= n){
            return 0;
        }
        if(dp.find({i, prev}) != dp.end()){
            return dp[{i,prev}];
        }
        int result1 = 1e9+1;
        if(arr1[i] > prev){
            result1 = solve(i+1, arr1, arr2, arr1[i]);
        }
        int result2 = 1e9+1;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if(it != arr2.end()){
            int j = it - arr2.begin();
            result2 = 1 + solve(i+1, arr1, arr2, arr2[j]);
        }
        return dp[{i, prev}] = min(result1, result2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        n = arr1.size();
        dp.clear();

        int result =  solve(0, arr1, arr2, INT_MIN);

        return result == 1e9+1 ? -1 : result;
    }
};
