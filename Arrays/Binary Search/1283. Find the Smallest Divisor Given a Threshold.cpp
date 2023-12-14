class Solution {
public:
    int findSum(vector<int>& nums, int i){
        int sum = 0;
        for(int j = 0;j<nums.size();j++){
            sum += ceil((double)nums[j]/(double)i);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = INT_MAX;
        // int maxE = *max_element(nums.begin(), nums.end());
        // for(int i = 1;i<=maxE;i++){
        //     int sum = 0;
        //     for(int j = 0;j<nums.size();j++){
        //         sum += ceil((double)nums[j]/(double)i);
        //         // cout<<ceil((double)nums[j]/(double)i)<<" ";
        //     }
        //     // cout<<sum<<" "<<i<<" "<<ans<<endl;
        //     // cout<<endl;
        //     if(sum <= threshold){
        //         ans = min(ans, i);
        //     }
        // }

        int l = 1;
        int h = *max_element(nums.begin(), nums.end());

        while(l <= h){
            int mid = l + (h - l)/2;
            if(findSum(nums, mid) <= threshold){
                ans = min(ans, mid);
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};
