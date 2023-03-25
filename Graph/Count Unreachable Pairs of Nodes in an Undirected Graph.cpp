class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited, long long &Size){
        visited[u] = true;
        Size++;
        for(int &v:adj[u]){
            if(!visited[v]){
                dfs(v, adj, visited, Size);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec: edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        long long remainNode = n;
        long long result = 0;

        for(int i = 0;i<n;i++){
            if(!visited[i]){
                long long Size = 0;
                dfs(i, adj, visited, Size);
                result += (Size)*(remainNode-Size);
                remainNode -= Size;
            }
        }
        return result;
    }
};
