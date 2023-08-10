class Solution {
public:
    int findPivot(vector<int>& nums, int l, int r){
        while(l < r){
            //skip duplicate
            while(l < r && nums[l] == nums[l+1]){
                l++;
            }
            while(l < r && nums[r] == nums[r-1]){
                r--;
            }

            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return r;
    }
    bool binarySearch(vector<int>& nums, int l, int r, int& target){
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return true;
            }else if(nums[mid] > target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int p = findPivot(nums, 0, n-1);

        if(binarySearch(nums, 0, p-1, target)){//binary search on left of pivot
            return true;
        }

        if(binarySearch(nums, p, n-1, target)){// binary search on right of pivot
            return true;
        }

        return false;
    }
};
