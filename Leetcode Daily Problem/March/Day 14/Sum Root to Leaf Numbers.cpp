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
    int solve(TreeNode* root, int cur){
        if(root == NULL){
            return 0;
        }
        cur = (cur*10)+root->val;
        //leaf node
        if(root->left == NULL && root->right == NULL){
            return cur;
        }

        int l = solve(root->left,cur);
        int r = solve(root->right,cur);
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};
