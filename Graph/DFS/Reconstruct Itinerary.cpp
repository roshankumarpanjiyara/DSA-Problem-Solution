class Solution {
public:
    vector<string> result;
    unordered_map<string, vector<string>> adj;
    int n;
    bool DFS(string fromAirport, vector<string>& path){
        path.push_back(fromAirport);
        if(path.size() == n+1){
            result = path;
            return true;
        }

        vector<string>& neighbours = adj[fromAirport];
        for(int i = 0;i<neighbours.size();i++){
            string toAirport = neighbours[i];
            neighbours.erase(neighbours.begin()+i);

            if(DFS(toAirport, path) == true){
                return true;
            }

            neighbours.insert(neighbours.begin()+i, toAirport);
        }

        path.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();

        for(auto &it : tickets){
            string u = it[0];
            string v = it[1];

            adj[u].push_back(v);
        }

        for(auto &edges : adj){
            sort(begin(edges.second), end(edges.second));
        }

        vector<string> path;
        DFS("JFK", path);

        return result;
    }
};
