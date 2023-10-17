class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, int> childParent;
        unordered_map<int, vector<int>> adj;
        for(int i = 0;i<n;i++){
            int node = i;
            if(leftChild[i] != -1){
                adj[i].push_back(leftChild[i]);
                if(childParent.find(leftChild[i]) != childParent.end()){
                    return false;
                }
                childParent[leftChild[i]] = node;
            }
            if(rightChild[i] != -1){
                adj[i].push_back(rightChild[i]);
                if(childParent.find(rightChild[i]) != childParent.end()){
                    return false;
                }
                childParent[rightChild[i]] = node;
            }
        }

        int root = -1;
        for(int i = 0;i<n;i++){
            if(childParent.find(i) == childParent.end()){
                if(root != -1){
                    return false;
                }
                root = i;
            }
        }

        if(root == -1){
            return false;
        }

        int count = 0;
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(root);
        count = 1;
        visited[root] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &v : adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    count++;
                    q.push(v);
                }
            }
        }

        if(count == n){
            return true;
        }
        return false;
    }
};
