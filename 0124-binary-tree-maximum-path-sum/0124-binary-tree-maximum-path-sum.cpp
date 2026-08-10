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
    int maxSum = -1000;
    int dfs(TreeNode* root){
        if(!root)return 0;

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        if(leftSum > 0 || rightSum > 0){
            maxSum = max(maxSum, root->val + max(leftSum, rightSum));
        }

        maxSum = max(maxSum, root->val); // for negative nums
        maxSum = max(maxSum, root->val + leftSum + rightSum);
        return max(max(leftSum, rightSum) + root->val, root->val);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};