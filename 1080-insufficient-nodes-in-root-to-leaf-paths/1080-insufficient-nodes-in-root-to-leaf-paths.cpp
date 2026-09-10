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
    int give(TreeNode*& root, int currSum, int limit){
        if(!root)return -1e6;

        currSum += root->val;
        int n1 = give(root->left, currSum, limit);
        int n2 = give(root->right, currSum, limit);

        int maxVal = max(n1, n2);
        maxVal = (maxVal == -1e6 ? 0 : maxVal);

        int currValue = root->val;
        if(maxVal + currSum < limit)root = nullptr;

        return maxVal + currValue;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        give(root, 0, limit);
        return root;
    }
};