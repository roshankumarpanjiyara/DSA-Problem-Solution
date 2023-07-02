class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it:flights){
            int u = it[0];
            int v = it[1];
            int c = it[2];

            adj[u].push_back({v, c});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;
        q.push({0,{src,0}});//{stop, {node, dist}}
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(node == dst || stop == k+1){
                continue;
            }

            for(auto it : adj[node]){
                int v = it.first;
                int c = it.second;

                if(cost + c < dist[v]){
                    dist[v] = cost + c;
                    q.push({stop + 1,{v, cost + c}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
