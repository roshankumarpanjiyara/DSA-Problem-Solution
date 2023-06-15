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
    int maxLevelSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = 0;
        int level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            level++;

            for(int i = 0;i<size;i++){
                if(q.front()->left != NULL){
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL){
                    q.push(q.front()->right);
                }
                sum += q.front()->val;
                q.pop();
            }

            if(sum > maxi){
                maxi = sum;
                ans = level;
            }
        }

        return ans;
    }
};
