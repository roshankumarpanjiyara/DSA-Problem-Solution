class Solution {
private:
    bool dfs(int node, vector<int> adj[], int vis[], int path[]){
        vis[node] = 1;
        path[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, path) == true){
                    return true;
                }
            }else if(path[it]){
                return true;
            }
        }
        path[node] = 0;
        return false;
    }
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // int vis[V] = {0};
        // int path[V] = {0};
        
        // for(int i = 0;i<V;i++){
        //     if(!vis[i]){
        //         if(dfs(i, adj, vis, path) == true){
        //             return true;
        //         }
        //     }
        // }
        
        // return false;
        
        int indegree[V] = {0};
        for(int i = 0;i< V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(count == V){
            return false;
        }
        return true;
    }
};
