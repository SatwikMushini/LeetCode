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

        vector<int>pre, ino, post;
        unordered_set<TreeNode*>seenpre, seenino, seenpost;
        stack<TreeNode*>stk;
        stk.push(root);

        while(!stk.empty()){
            TreeNode* node = stk.top();
            if(!seenpre.count(node)){
                pre.push_back(node->val);
                seenpre.insert(node);
                continue;
            } 

            if(!node->left || seenino.count(node->left)){
                if(!seenino.count(node))ino.push_back(node->val);
                seenino.insert(node);
            }
            else{
                stk.push(node->left); continue;
            }
            if((!node->left || seenpost.count(node->left)) 
                && (!node->right || seenpost.count(node->right))){
                post.push_back(node->val);
                seenpost.insert(node);
                stk.pop();
            }
            else{
                stk.push(node->right);
            }

        }
        vector<vector<int>> ans = {pre, ino, post};

        return ino;
    }
};