class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root==NULL){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }

        if(val<root->val){
            root->left=insertIntoBST(root->left, val);
        }
        if(val>root->val){
            root->right= insertIntoBST(root->right, val);
        }

        return root;
        }
};