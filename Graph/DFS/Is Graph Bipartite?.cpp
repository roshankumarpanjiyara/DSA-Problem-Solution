class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& color, int curColor){
        color[u] = curColor;

        for(auto &v: graph[u]){
            if(color[v] == color[u]){
                return false;
            }
            if(color[v] == -1){
                int colorV = 1-curColor;
                if(dfs(v, graph, color, colorV) == false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                if(dfs(i, graph, color, 1) == false){
                    return false;
                }
            }
        }

        return true;
    }
};
