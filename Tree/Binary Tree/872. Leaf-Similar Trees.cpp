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
    void solve(TreeNode* root, vector<int>& vt){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            vt.push_back(root->val);
        }
        solve(root->left, vt);
        solve(root->right, vt);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t;
        vector<int> p;

        solve(root1, t);
        solve(root2, p);

        return t == p;
    }
};
