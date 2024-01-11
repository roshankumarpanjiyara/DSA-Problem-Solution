Brute Force
class Solution {
public:
    int maxDiff;
    void findMaxDiff(TreeNode* root, TreeNode* child){
        if(root == NULL || child == NULL){
            return;
        }
        maxDiff = max(maxDiff, abs(root->val - child->val));

        findMaxDiff(root, child->left);
        findMaxDiff(root, child->right);
    }
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }
        findMaxDiff(root, root->left);
        findMaxDiff(root, root->right);

        solve(root->left);
        solve(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        maxDiff = -1;
        solve(root);
        return maxDiff;
    }
};
Optimal
class Solution {
    int solve(TreeNode root, int a, int b){
        if(root == null){
            return Math.abs(a - b);
        }

        int left = solve(root.left, Math.max(a, root.val), Math.min(b, root.val));
        int right = solve(root.right, Math.max(a, root.val), Math.min(b, root.val));
        
        return Math.max(left, right);
    }
    public int maxAncestorDiff(TreeNode root) {
        return solve(root, root.val, root.val);
    }
}
