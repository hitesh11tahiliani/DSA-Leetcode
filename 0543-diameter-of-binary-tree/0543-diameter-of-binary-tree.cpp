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
    int height(TreeNode* root) {
        if (!root)
            return 0;
        
        int maxLeft = height(root->left);
        int maxRight = height(root->right);
        
        return max(maxLeft, maxRight)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        
        int h1 = diameterOfBinaryTree(root->left);
        int h2 = diameterOfBinaryTree(root->right);
        int h3 = height(root->left)+height(root->right);
        
        int ans = max(h1, max(h2, h3));
        return ans;
    }
};