class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0;
        for(int i : nums){
            target += i;
        }
        target = target - x;

        int j = 0;
        int i = 0;
        int n = nums.size();
        int sum = nums[0];
        int maxLen = INT_MIN;

        while(i < n){
            while(j <= i && sum > target){
                sum -= nums[j];
                j++;
            }
            if(sum == target){
                maxLen = max(maxLen, i - j + 1);
            }
            i++;
            if(i < n){
                sum += nums[i];
            }
        }

        //cout<<maxLen<<endl;

        return maxLen == INT_MIN ? -1 : n - maxLen;
    }
};
