void solve(int i, int N, vector<string>& ans, string temp, bool flag){
    if(i >= N){
        ans.push_back(temp);
        return;
    }
    solve(i + 1, N, ans, temp + '0', false);
    if(flag == false){
        solve(i+1, N, ans, temp + '1', true);
    }
}
vector<string> generateString(int N) {
    // Write your code here.
    vector<string> ans;
    solve(0, N, ans, "", false);
    return ans;
}
