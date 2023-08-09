class Solution {
public:
    bool isValid(vector<int>& nums, int minDiff, int p){
        int count = 0;
        for(int i = 0;i<nums.size()-1;i++){
            if(abs(nums[i] - nums[i+1]) <= minDiff){
                count++;
                i++;
            }
        }
        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums[nums.size()-1] - nums[0];
        int result = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(isValid(nums, mid, p)){
                result = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return result;
    }
};
