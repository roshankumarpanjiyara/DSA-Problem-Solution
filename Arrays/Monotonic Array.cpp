class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() < 2){
            return true;
        }
        int inc = 0;
        int dec = 0;

        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1]){
                dec++;
            }else if(nums[i] < nums[i+1]){
                inc++;
            }
        }

        cout<<inc<<" "<<dec;

        if(inc == 0|| dec == 0){
            return true;
        }
        return false;
    }
};
