class Solution {
public:
    int n, m;
    int t[505][505];
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
        if(i >= n || j >= m){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(nums1[i] == nums2[j]){
            return t[i][j] = 1 + solve(i+1, j+1, nums1, nums2);
        }

        return t[i][j] = max(solve(i, j+1, nums1, nums2), solve(i+1, j, nums1, nums2));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        memset(t, -1, sizeof(t));

        return solve(0, 0, nums1, nums2);
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        vector<vector<int>> t(n+1, vector<int>(m+1));

        for(int i = 0;i<n+1;i++){
            for(int j = 0;j<m+1;j++){
                if(i == 0 || j == 0){
                    t[i][j] = 0;
                }else{
                    if(nums1[i-1] == nums2[j-1]){
                        t[i][j] = 1 + t[i-1][j-1];
                    }else{
                        t[i][j] = max(t[i][j-1], t[i-1][j]);
                    }
                }
            }
        }

        return t[n][m];
    }
};
