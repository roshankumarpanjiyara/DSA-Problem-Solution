class DisjointSet{
    public:
        vector<int> size, parent;
        DisjointSet(int n){
            size.resize(n+1, 0);
            parent.resize(n+1, 0);
            for(int i = 0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u, int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);

            if(ulp_u == ulp_v){
                return;
            }
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> adj;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                int u = i;
                int v = j;
                adj.push_back({dist, {u, v}});
            }
        }
        
        sort(adj.begin(), adj.end());
        int minDist = 0;
        DisjointSet ds(n);
        for(auto it: adj){
            int dist = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findParent(u) != ds.findParent(v)){
                minDist += dist;
                ds.unionBySize(u, v);
            }
        }

        return minDist;
    }
};
