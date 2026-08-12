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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>ans;

        queue<TreeNode*>q;
        q.push(root);

        int cnt = 0;
        while(!q.empty()){
            int qs = q.size();
            vector<int>level_ele; //to store each level elements
            while(qs--){
                TreeNode* node = q.front(); q.pop();
                level_ele.push_back(node->val);

                if(node->left)q.push(node->left); if(node->right)q.push(node->right);
            }
            if(cnt & 1)reverse(level_ele.begin(), level_ele.end()); // reverse if level is odd
            ans.push_back(level_ele);
            cnt++;
        }

        return ans;
    }
};