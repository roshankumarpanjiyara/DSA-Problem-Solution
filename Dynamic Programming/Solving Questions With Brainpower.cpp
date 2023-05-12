class Solution {
public:
  //recursion + memo
    int n;
    long long solve(int i, vector<vector<int>>& questions, vector<long long>& t){
        if(i >= n){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        long long take = questions[i][0] + solve(i + questions[i][1] + 1, questions, t);
        long long not_take = solve(i+1, questions, t);

        return t[i] = max(take, not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        vector<long long> t(n, -1);
        return solve(0, questions, t);
    }


//bottom up
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
         
        if(n == 1){
            return questions[0][0];
        }
        vector<long long> t(200001, 0);

        for(int i = n-1;i>=0;i--){
            t[i] = max(questions[i][0] + t[i + questions[i][1] + 1], t[i + 1]);
        }
        return t[0];
    }
};
