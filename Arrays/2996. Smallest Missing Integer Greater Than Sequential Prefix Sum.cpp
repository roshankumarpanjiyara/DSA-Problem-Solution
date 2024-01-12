class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1] + 1 == nums[i]){
                sum += nums[i];
            }else{
                break;
            }
        }

        cout<<sum;

        unordered_set<int> st(nums.begin(), nums.end());
        while(true){
            if(st.find(sum) == st.end()){
                return sum;
            }
            sum++;
        }

        return sum;
    }
};
