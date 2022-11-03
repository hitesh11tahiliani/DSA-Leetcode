class Solution {
public:
    bool isValidBSTHelper (TreeNode* currentNode, TreeNode* min, TreeNode* max) {
        if (currentNode==NULL) return true;               
        if (min && currentNode->val <= min->val) return false;
        if (max && currentNode->val >= max->val) return false;

        return isValidBSTHelper (currentNode->left, min, currentNode) && isValidBSTHelper (currentNode->right, currentNode, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper (root, NULL, NULL);
    }
};