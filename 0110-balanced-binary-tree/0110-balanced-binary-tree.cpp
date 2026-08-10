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
    bool ans = true;
    int depth(TreeNode* root){
        if(!root)return 0;

        int d1 = 1 + depth(root->left);
        int d2 = 1 + depth(root->right);

        if(abs(d1-d2) >= 2)ans = false;
        return max(d1, d2);
    }
    bool isBalanced(TreeNode* root) {
        depth(root);
        return ans;
    }
};