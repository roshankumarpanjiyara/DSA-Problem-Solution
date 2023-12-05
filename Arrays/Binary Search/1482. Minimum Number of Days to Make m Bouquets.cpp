class Solution {
public:
    int calc(vector<int>& bloomDay, int mid, int k){
        int count = 0;
        int bouq = 0;
        for(int i : bloomDay){
            if(i <= mid){
                count++;
            }else{
                count = 0;
            }
            if(count == k){
                bouq++;
                count = 0;
            }
        }

        return bouq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long long)((long long)m * (long long)k) > n){
            return -1;
        }

        int ans = *max_element(begin(bloomDay), end(bloomDay));
        int l = 0;
        int r = *max_element(begin(bloomDay), end(bloomDay));

        while(l <= r){
            int mid = l + (r-l)/2;
            if(calc(bloomDay, mid, k) >= m){
                ans = min(ans, mid);
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
