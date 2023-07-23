class DisjointSet{
  vector<int> parent, size;
  public:
    DisjointSet(int n){
      parent.resize(n+1);
      size.resize(n+1, 0);
      for(int i = 0;i<=n;i++){
        parent[i] = i;
      }
    }
    int findParent(int node){
      if(node == parent[node]){
        return node;
      }
      return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v){
      int ulp_u = findParent(u);      
      int ulp_v = findParent(v);
      if(ulp_u == ulp_v){
        return;
      }
      if(size[ulp_u] < size[ulp_v]){
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u]; 
      }else{
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v]; 
      }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMail;

        for(int i = 0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapMail.find(mail) == mapMail.end()){
                    mapMail[mail] = i;
                }else{
                    ds.unionBySize(i, mapMail[mail]);
                }
            }
        }

        vector<string> mergeMail[n];
        for(auto it : mapMail){
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> result;
        for(int i = 0;i<n;i++){
            if(mergeMail[i].size() == 0){
                continue;
            }
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMail[i]){
                temp.push_back(it);
            }
            result.push_back(temp);
        }
        return result;
    }
};
