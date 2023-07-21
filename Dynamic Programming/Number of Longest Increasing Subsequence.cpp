class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        vector<int> count(n,1);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j]){
                    if(t[j]+1 == t[i]){
                        count[i] += count[j];
                    }else if(t[j] + 1 > t[i]){
                        t[i] = t[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
        }

        int maxVal =  *max_element(begin(t), end(t));
        int result = 0;

        for(int i = 0;i<n;i++){
            if(t[i] == maxVal){
                result += count[i];
            }
        }

        return result;
    }
};
