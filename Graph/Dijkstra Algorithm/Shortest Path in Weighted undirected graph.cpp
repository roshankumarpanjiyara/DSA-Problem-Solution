//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int, int>> adj[n+1];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int d = it[2];
            
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,1});
        
        vector<int> dist(n+1, 1e9);
        vector<int> parent(n+1);
        for(int i = 1;i<n+1;i++){
            parent[i] = i;
        }
        dist[1] = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int weight = it.second;
                
                if(dis + weight < dist[adjNode]){
                    dist[adjNode] = dis + weight;
                    pq.push({dis+weight, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if(dist[n] == 1e9){
            return {-1};
        }
        int node = n;
        vector<int> path;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};
