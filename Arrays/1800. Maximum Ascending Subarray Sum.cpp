class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = nums[0];

        if(nums.size() == 1){
            return nums[0];
        }

        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] < nums[i+1]){
                sum += nums[i+1];
            }else{
                maxSum = max(maxSum, sum);
                sum = nums[i+1];
            }
            maxSum = max(maxSum, sum);
            cout<<maxSum<<" "<<sum<<endl;
        }

        return maxSum;
    }
};
