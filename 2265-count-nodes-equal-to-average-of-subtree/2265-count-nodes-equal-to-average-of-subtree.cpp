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
    int ans = 0;
    pair<int,int> give(TreeNode* root){
        if(!root)return {0,0};

        auto lpair = give(root->left);
        auto rpair = give(root->right);

        int sum = root->val + lpair.first + rpair.first;
        int cnt = 1 + lpair.second + rpair.second;

        ans += (sum / cnt == root->val);
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        give(root);
        return ans;
    }
};