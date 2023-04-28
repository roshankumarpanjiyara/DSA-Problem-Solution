class Solution {
public:
    bool isSimilar(string &s1, string &s2){
        int dif = 0;

        for(int i = 0;i<s1.length();i++){
            if(s1[i] != s2[i]){
                dif++;
            }
        }

        return dif == 0 || dif == 2;
    }

    void dfs(int u, unordered_map<int, vector<int>> &adj, vector<int> &visited){
        visited[u] = true;

        for(int &v:adj[u]){
            if(!visited[v]){
                dfs(v, adj, visited);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        unordered_map<int, vector<int>> adj;

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(isSimilar(strs[i], strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n, false);

        int count = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            }
        }

        return count;
    }
};
