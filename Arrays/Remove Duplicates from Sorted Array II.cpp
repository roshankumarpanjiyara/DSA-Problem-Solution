class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c = 0;

        if(nums.size() <= 2){
            return nums.size();
        }

        for(int i = 0;i<nums.size()-2;i++){
            if(nums[i] != nums[i+2]){
                nums[c++] = nums[i];
            }
        }
        nums[c++] = nums[nums.size()-2];
        nums[c++] = nums[nums.size()-1];

        return c;
    }
};
