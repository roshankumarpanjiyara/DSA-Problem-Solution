class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0;
        int h = arr.size()-1;
        int missing  = 0;

        while(l <= h){
            int mid = l + (h - l)/2;
            missing = arr[mid] - (mid + 1);

            if(k > missing){
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }

        return h + 1 + k;
    }
};
