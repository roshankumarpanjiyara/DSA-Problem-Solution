/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void makeGraph(unordered_map<int, vector<int>>& adj, int parent, TreeNode* curr){
        if(curr == NULL){
            return;
        }
        if(parent != -1){
            adj[curr->val].push_back(parent);
        }
        if(curr->left != NULL){
            adj[curr->val].push_back(curr->left->val);
        }
        if(curr->right != NULL){
            adj[curr->val].push_back(curr->right->val);
        }

        makeGraph(adj, curr->val, curr->left);
        makeGraph(adj, curr->val, curr->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root);//O(n)

        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);
        int minutes = 0;

        while(!q.empty()){//O(n)
            int n = q.size();
            while(n--){
                int cur = q.front();
                q.pop();

                for(auto &it : adj[cur]){
                    if(visited.find(it) == visited.end()){
                        q.push(it);
                        visited.insert(it);
                    }
                }
            }
            minutes++;
        }

        return minutes-1;
    }
};
