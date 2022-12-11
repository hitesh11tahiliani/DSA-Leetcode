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
    int maxSum;
int maxPathSum(TreeNode* root) {
    maxSum = INT_MIN;
    dfs(root);
    return maxSum;
}
// post order
int dfs(TreeNode *root) {
    if (!root) return 0;
     int l = dfs(root->left);
     int r = dfs(root->right);
     maxSum = max(maxSum, root->val + (l > 0 ? l : 0) + (r > 0 ? r : 0));
     return (max(l, r) > 0 ? max(l, r) : 0) + root->val;
}
};