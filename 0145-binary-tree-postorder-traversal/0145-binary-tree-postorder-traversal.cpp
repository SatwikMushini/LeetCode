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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)return {};

        vector<int>ans;
        stack<TreeNode*>stk;
        unordered_set<TreeNode*>seen;

        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();

            if(node->left && !seen.count(node->left)){
                stk.push(node->left);
            }
            else if(node->right && !seen.count(node->right)){
                stk.push(node->right);
            }
            else{
                ans.push_back(node->val);
                seen.insert(node);
                stk.pop();
            }
        }

        return ans;

    }
};