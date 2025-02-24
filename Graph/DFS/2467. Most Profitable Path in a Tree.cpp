class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobTime;
    int aliceAmount;

    bool DFSBob(int curr, int t, vector<bool>& visited){
        visited[curr] = true;
        bobTime[curr] = t;
        if(curr == 0){
            return true;
        }

        for(auto &ngbr: adj[curr]){
            if(!visited[ngbr]){
                if(DFSBob(ngbr, t+1, visited) == true){
                    return true;
                }
            }
        }

        bobTime.erase(curr);
        return false;

    }

    void DFSAlice(int curr, int t, int income, vector<bool>& visited, vector<int>& amount){
        visited[curr] = true;

        if(bobTime.find(curr) == bobTime.end() || t < bobTime[curr]){
            income += amount[curr];
        }else if(t == bobTime[curr]){
            income += (amount[curr]/2);
        }

        if(adj[curr].size() == 1 && curr != 0){
            aliceAmount = max(aliceAmount, income);
        }

        for(auto &ngbr: adj[curr]){
            if(!visited[ngbr]){
                DFSAlice(ngbr, t+1, income, visited, amount);
            }
        }

    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();
        aliceAmount = INT_MIN;

        for(auto &vec: edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        DFSBob(bob, 0, visited);

        visited.assign(n, false);
        DFSAlice(0, 0, 0, visited, amount);

        return aliceAmount;
    }
};
