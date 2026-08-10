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
    vector<vector<int>> ans;
    void lot(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int qs = q.size();
            vector<int>ds;
            while(qs--){
                TreeNode* node = q.front();
                ds.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                q.pop();
            }
            ans.push_back(ds);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        lot(root);
        return ans;
    }
};