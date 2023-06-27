class Solution {
public:
    int maxTime = 0;
    void DFS(unordered_map<int, vector<int>>& adj, vector<int>& informTime, int curEmployee, int curTime){
        maxTime = max(maxTime, curTime);

        for(auto &employee : adj[curEmployee]){
            DFS(adj, informTime, employee, curTime + informTime[curEmployee]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;

        for(int i = 0;i < manager.size();i++){
            int employee_i = i;
            int manager_i = manager[i];

            adj[manager_i].push_back(employee_i);
        }

        DFS(adj, informTime, headID, 0);

        return maxTime;
    }
};
