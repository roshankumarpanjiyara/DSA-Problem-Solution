class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long totalSum = 0;
        vector<long> temp;
        for(int n : nums){
            totalSum += n;
            temp.push_back(totalSum);
        }
        int ans = 0;
        for(int i = 0;i<nums.size()-1;i++){
            long rightSum = temp[i];
            long leftSum = totalSum - temp[i];
            if(rightSum >= leftSum){
                ans++;
            }
        }

        return ans;
    }
};
