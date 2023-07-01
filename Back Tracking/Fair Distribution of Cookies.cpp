class Solution {
public:
    int result = INT_MAX;
    int n;
    void solve(int idx, vector<int>& children, vector<int>& cookies, int k){
        if(idx >= n){
            int unfair = *max_element(children.begin(), children.end());
            result = min(result, unfair);
            return;
        }
        int cookie = cookies[idx];
        for(int i = 0;i<k;i++){
            children[i] += cookie;
            solve(idx+1, children, cookies, k);
            children[i] -= cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        n = cookies.size();

        solve(0, children, cookies, k);

        return result;
    }
};
