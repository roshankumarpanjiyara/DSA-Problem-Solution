class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for(auto vec : roads){
            int u = vec[0];
            int v = vec[1];
            int t = vec[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        vector<long long> dist(n, LONG_MAX);
        dist[0] = 0;

        vector<long long> ways(n, 0);
        ways[0] = 1;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            long long time = it.first;

            for(auto it : adj[node]){
                int adjNode = it.first;
                long long weight = it.second;
                
                if(weight + time < dist[adjNode]){
                    dist[adjNode] = weight + time;
                    pq.push({weight + time, adjNode});
                    ways[adjNode] = ways[node] % MOD;   
                }else if(weight + time == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};
