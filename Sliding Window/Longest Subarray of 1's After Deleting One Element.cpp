class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int count0 = 0;
        int longest = INT_MIN;

        while(i < nums.size()){
            if(nums[i] == 0){
                count0++;
            }
            while(j < nums.size() && count0 > 1){
                if(nums[j] == 0){
                    count0--;
                }
                // i++;
                j++;
            }

            longest = max(longest, i - j);
            i++;
        }
        return longest;
    }
};
