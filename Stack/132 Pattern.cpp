class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        // for(int i = 0;i<n-2;i++){
        //     for(int j = i+1;j<n-1;j++){
        //         for(int k = j+1;k<n;k++){
        //             if(nums[i] < nums[k] && nums[k] < nums[j]){
        //                 return true;
        //             }
        //         }
        //     }
        // }

        int num3 = INT_MIN; //j
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            if(nums[i] < num3){
                return true;
            }

            while(!st.empty() && st.top() < nums[i]){
                num3 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};
