class Solution {
public:
    int t[1001][1001];
    bool isPred(string &A, string &B){
        int n = A.size();
        int m = B.size();

        if(n >= m || abs(m-n) != 1){
            return false;
        }

        int i = 0;
        int j = 0;

        while(i < n && j < m){
            if(A[i] == B[j]){
                i++;
            }
            j++;
        }

        return i == n;
    }
    int lis(vector<string>& words, int prev, int curr){
        if(curr == words.size()){
            return 0;
        }
        if(prev != -1 && t[prev][curr] != -1){
            return t[prev][curr];
        }
        int take = 0;
        if(prev == -1 || isPred(words[prev], words[curr])){
            take = 1 + lis(words, curr, curr + 1);
        }
        int not_take = lis(words, prev, curr + 1);

        if(prev != -1){
            t[prev][curr] = max(take, not_take);
        }

        return max(take, not_take);
    }
    static bool myFun(string &A, string &B){
        return A.length() < B.length();
    }
    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
        sort(words.begin(), words.end(), myFun);
        return lis(words, -1, 0);
    }
};
