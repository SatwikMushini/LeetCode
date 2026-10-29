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
    bool solve(int sum, TreeNode* root, int targetSum) {
        if(!root->left && !root->right){
            if(sum + root->val == targetSum)return true;
        }
        if(root->left){
            if(solve(sum+root->val, root->left, targetSum))return true;
        }
        if(root->right){
            if(solve(sum+root->val, root->right, targetSum))return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        return solve(0, root, targetSum);
    }
};