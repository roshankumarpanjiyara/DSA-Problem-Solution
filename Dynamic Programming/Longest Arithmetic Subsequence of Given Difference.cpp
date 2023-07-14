class Solution {
public:
    // int n, d;
    // int solve(int idx, vector<int>& arr){
    //     int result = 0;
    //     for(int i = idx + 1;i<n;i++){
    //         int prev = arr[idx];
    //         int curr = arr[i];
    //         if(curr - prev == d){
    //             result = max(result, 1 + solve(i, arr));
    //         }
    //     }
    //     return result;
    // }
    int longestSubsequence(vector<int>& arr, int difference) {
        // n = arr.size();
        // d = difference;

        // int result = 0;
        // for(int i = 0;i<n;i++){
        //     result = max(result, 1 + solve(i, arr));
        // }
        // return result;

        unordered_map<int, int> mp;
        int result = 0;
        for(int i = 0;i < arr.size();i++){
            int curr = arr[i];
            int prev = arr[i] - difference;

            int prev_length = mp[prev];
            mp[curr] = prev_length + 1;
            result = max(result, mp[curr]);
        }
        return result;
    }
};
