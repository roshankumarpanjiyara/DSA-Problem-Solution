class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long ans = -1;

        sort(nums.begin(), nums.end());
        for(int i = 0;i<n;i++){
            if(sum > nums[i]){
                ans = nums[i] + sum;
            }
            sum += nums[i];
        }

        return ans;
    }
};
