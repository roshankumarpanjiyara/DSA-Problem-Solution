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
    int sum;
    void solve(TreeNode* root, int low, int high){
        if(root == NULL){
            return;
        }
        if(root->val >= low && root->val <= high){
            sum += root->val;
        }
        // cout<<root->val<<endl;
        solve(root->left, low, high);
        solve(root->right, low, high);

        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        solve(root, low, high);
        return sum;
    }
};
