class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int time = it.first;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int weight = it.second;

                if(weight + time < dist[adjNode]){
                    dist[adjNode] = weight + time;
                    pq.push({weight+time, adjNode});
                }
            }
        }

        int answer = INT_MIN;
        for (int i = 1; i <= n; i++) {
            answer = max(answer, dist[i]);
        }
        
        // INT_MAX signifies atleat one node is unreachable
        return answer == 1e9 ? -1 : answer;
    }
};
