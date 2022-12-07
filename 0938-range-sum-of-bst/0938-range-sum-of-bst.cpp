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
    
    int sum =0;
    
    int solve(TreeNode* root, int low, int high){
        if (root!=NULL){
            solve(root->left, low, high);
            solve(root->right, low, high);
            if (root->val >= low and root->val <= high){
                sum += root->val;
            }
        }
        return sum;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL){
            return 0;
        }
        
        return solve (root, low, high);
    }
};