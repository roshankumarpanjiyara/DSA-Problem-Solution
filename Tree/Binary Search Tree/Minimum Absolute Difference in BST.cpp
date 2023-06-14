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
  //approach 1
    void inorder(TreeNode* root, vector<int>& tree){
        if(root == NULL){
            return;
        }
        inorder(root->left, tree);
        tree.push_back(root->val);
        inorder(root->right, tree);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> tree;
        inorder(root, tree);

        int mini = INT_MAX;
        for(int i = 0;i<tree.size()-1;i++){
            mini = min(mini, tree[i+1] - tree[i]);
        }
        return mini;
    }
  
  //approach 2
    int ans = INT_MAX;
    void inorder(TreeNode* root, TreeNode* &prev){
        if(root == NULL){
            return;
        }
        inorder(root->left, prev);
        if(prev != NULL){
            ans = min(ans, abs(prev->val - root->val));
        }
        prev = root;
        inorder(root->right, prev);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        inorder(root, prev);
        return ans;
    }
};
