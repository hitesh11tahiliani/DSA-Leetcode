
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     
        if(root==NULL)
            return NULL;
        
        if(root==p || root==q)
            return root;
        
        TreeNode* leftAns =lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns =lowestCommonAncestor(root->right,p,q);

        if(leftAns != NULL and rightAns != NULL )
            return root;
        
        else if(leftAns!=NULL and rightAns == NULL){
            return leftAns;
        }
        else if(leftAns == NULL and rightAns != NULL)
            return rightAns;

        else 
            return NULL;
        
    }
};