//recursion + memo

class Solution {
    int n;
    int t[] = new int[501];
    public int solve(int i, int[] arr, int k){
        if(i >= n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        int result = 0;
        int max = -1;

        for(int j = i;j<n && (j - i + 1) <= k; j++){
            max = Math.max(max, arr[j]);
            result = Math.max(result, (j - i + 1)*max + solve(j + 1, arr, k));
        }

        return t[i] = result;
    }
    public int maxSumAfterPartitioning(int[] arr, int k) {
        n = arr.length;
        Arrays.fill(t, -1);
        return solve(0, arr, k);
    }
}

//bottom up

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> t(n + 1, 0);

        for(int i = 0;i<=n;i++){
            int curMax = -1;
            for(int j = 1;j<=k && i - j >= 0; j++){
                curMax = max(curMax, arr[i - j]);
                t[i] = max(t[i], (curMax * j) + t[i-j]);
            }
        }

        return t[n];
    }
};
