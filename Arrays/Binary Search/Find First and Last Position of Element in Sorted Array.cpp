class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int ans = -1;

        while(l <= r){
            int mid = l +(r-l)/2;

            if(target == nums[mid]){
                ans = mid;
                r = mid-1;
            }else if(target > nums[mid]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
    int lastOcc(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int ans = -1;

        while(l <= r){
            int mid = l +(r-l)/2;

            if(target == nums[mid]){
                ans = mid;
                l = mid+1;
            }else if(target > nums[mid]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums, target);
        int last = lastOcc(nums, target);

        return {first, last};
    }
};
