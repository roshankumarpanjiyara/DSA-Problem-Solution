class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k;
        int j = k;
        int curMin = nums[k];
        int ans = nums[k];

        while(i > 0 || j < n-1){
            int left = i > 0 ? nums[i-1] : 0;
            int right = j < n-1 ? nums[j+1] : 0;

            if(left > right){
                i--;
                curMin = min(curMin, nums[i]);
            }else{
                j++;
                curMin = min(curMin, nums[j]);
            }

            ans = max(ans, curMin * (j - i + 1));
        }

        return ans;
    }
};
