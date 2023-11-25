//java
class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n];
        int[] suffix = new int[n];

        prefix[0] = nums[0];
        for(int i = 1;i<n;i++){
            prefix[i] = nums[i] + prefix[i-1];
        }

        suffix[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            suffix[i] = nums[i] + suffix[i+1];
        }

        int[] result = new int[n];

        for(int i = 0;i<n;i++){
            result[i] = ((nums[i] * i) - prefix[i]) + (suffix[i] - (nums[i] * (n-i-1)));
        }

        return result;

    }
}

//c++
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<n;j++){
        //         res[i] += abs(nums[i] - nums[j]); 
        //     }
        // }

        int sum = accumulate(begin(nums), end(nums), 0);
        int prefix = 0;

        for(int i = 0;i<n;i++){
            int leftSum = prefix;
            int rightSum = sum - prefix - nums[i];

            res[i] = ((nums[i] * i) - leftSum) + (rightSum - (nums[i] * (n-i-1)));
            prefix += nums[i];
        }

        return res;
    }
};
