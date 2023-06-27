class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);

        unordered_map<int, vector<int>> adj;

        for(auto vec : prerequisites){
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(count == numCourses){
            return true;
        }
        return false;
    }
};
