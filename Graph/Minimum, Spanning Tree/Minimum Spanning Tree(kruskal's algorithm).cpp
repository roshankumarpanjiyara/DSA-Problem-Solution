#include<bits/stdc++.h>
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
bool compare(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */

  DisjointSet ds(n);
  sort(edges.begin(), edges.end(), compare);
  int sum = 0;

  for(auto it : edges){
    int u = it[0];
    int v = it[1];
    int w = it[2];

    if(ds.findParent(u) != ds.findParent(v)){
      sum += w;
      ds.unionBySize(u, v);
    }
  }
  return sum;
}
