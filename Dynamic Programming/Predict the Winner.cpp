class Solution {
public:
//approach 1
     int solve(int i, int j, vector<int>& nums){
         if(j < i){
             return 0;
         }
         if(i == j){
             return nums[i];
         }
         int take_i = nums[i] + min(solve(i+2, j, nums), solve(i+1, j-1, nums));
         int take_j = nums[j] + min(solve(i+1, j-1, nums), solve(i, j-2, nums));
         return max(take_i, take_j);
     }
     bool PredictTheWinner(vector<int>& nums) {
         int p1 = solve(0, nums.size()-1, nums);
         int sum = 0;
         for(int i : nums){
             sum += i;
         }
         int p2 = sum - p1;
         if(p1 >= p2){
             return true;
         }
         return false;
     }

//approach 2

    int t[23][23];
    int solve(int i, int j, vector<int>& nums){
        if(j < i){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(i == j){
            return t[i][j] = nums[i];
        }
        int take_i = nums[i] - solve(i+1, j, nums);
        int take_j = nums[j] - solve(i, j-1, nums);

        return t[i][j] = max(take_i, take_j);
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(0, nums.size()-1, nums) >= 0;
    }
};
