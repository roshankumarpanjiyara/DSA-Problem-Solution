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
    int countNode(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1+countNode(root->left)+countNode(root->right);
    }
    bool dfs(TreeNode* root, int i, int total){
        if(root == NULL){
            return true;
        }
        if(i>total){
            return false;
        }
        return dfs(root->left,2*i,total) && dfs(root->right,2*i+1,total);
    }
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNode(root);
        int i = 1;
        
        return dfs(root, i, totalNodes);
    }
};
