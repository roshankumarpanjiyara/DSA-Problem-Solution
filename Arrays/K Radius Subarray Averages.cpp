class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);
        if(n < 2*k){
            return result;
        }
        vector<long long> prefix(n+1,0);
        prefix[1] = nums[0];
        for(int i = 1;i<n;i++){
            prefix[i+1] = prefix[i-1+1] + nums[i];
        }

        for(int i = k;i<n;i++){
            if(i+k < n){
                result[i] = (prefix[i+k+1] - prefix[i-k-1+1])/(2*k+1);
            }
        }
        return result;
    }
};
