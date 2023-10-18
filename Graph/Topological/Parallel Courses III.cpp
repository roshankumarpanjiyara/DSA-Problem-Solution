class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        vector<int> maxTime(n, 0);

        for(auto vec : relations){
            int u = vec[0] - 1;
            int v = vec[1] - 1;

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                maxTime[i] = time[i];
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &v : adj[u]){
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v]);
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return *max_element(maxTime.begin(), maxTime.end());
    }
};
