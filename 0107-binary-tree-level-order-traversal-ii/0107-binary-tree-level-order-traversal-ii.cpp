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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int current_level_nodes=q.size();
            vector<int>b;
            for(int i=0;i<current_level_nodes;i++)
            {
                TreeNode* c=q.front();
                q.pop();
                b.push_back(c->val);
                
                if(c->left)
                    q.push(c->left);
                if(c->right)
                    q.push(c->right);
                
            }
            ans.push_back(b);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};