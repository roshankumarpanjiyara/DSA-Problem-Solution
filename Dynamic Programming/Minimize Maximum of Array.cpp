class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int n){
        vector<long long> arr(begin(nums), end(nums));
        for(int i = 0;i<n-1;i++){
            if(arr[i] > mid){
                return false;
            }
            long long buffer = mid - arr[i];
            arr[i+1] = arr[i+1] - buffer;
        }
        return arr[n-1] <= mid;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int maxL = 0;
        int maxR = *max_element(begin(nums),end(nums));
        int result = 0;
        while(maxL<=maxR){
            int mid = maxL+(maxR-maxL)/2;
            if(isValid(nums, mid, n)){
                result = mid;
                maxR = mid-1;
            }else{
                maxL = mid+1;
            }
        }
        return result;
    }
};
