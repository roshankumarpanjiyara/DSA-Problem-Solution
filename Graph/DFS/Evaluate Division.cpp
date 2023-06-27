class Solution {
public:
    void dfs(string s, string d, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& visited, double product, double &ans){
        if(visited.find(s) != visited.end()){
            return;
        }
        visited.insert(s);
        if(s == d){
            ans = product;
            return;
        }

        for(auto &p : adj[s]){
            string v = p.first;
            double val = p.second;

            dfs(v, d, adj, visited, product*val, ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        for(int i = 0;i<values.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0/val});
        }

        vector<double> res;

        for(auto &query: queries){
            string s = query[0];
            string d = query[1];
            double ans = -1.0;
            double product = 1.0;

            if(adj.find(s) != adj.end()){
                unordered_set<string> visited;
                dfs(s, d, adj, visited, product, ans);
            }

            res.push_back(ans);
        }

        return res;
    }
};
