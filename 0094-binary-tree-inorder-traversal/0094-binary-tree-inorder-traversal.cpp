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
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int>ans;
        
        stack<TreeNode*>stk;
        unordered_set<TreeNode*>seen;

        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            if(!node->left || seen.count(node->left)){
                ans.push_back(node->val);
                seen.insert(node);
                stk.pop();
                if(node->right)stk.push(node->right);
            }
            else{
                stk.push(node->left);
            }
        }
        return ans;
    }
};