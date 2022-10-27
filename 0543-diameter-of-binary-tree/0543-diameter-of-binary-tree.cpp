class Solution {
public:
    
    // TC = O(N^2)
//     int height(TreeNode* root) {
//         if (!root)
//             return 0;
        
//         int maxLeft = height(root->left);
//         int maxRight = height(root->right);
        
//         return max(maxLeft, maxRight)+1;
//     }
    
//     int diameterOfBinaryTree(TreeNode* root) {
//         if (!root)
//             return 0;
        
//         int h1 = diameterOfBinaryTree(root->left);
//         int h2 = diameterOfBinaryTree(root->right);
//         int h3 = height(root->left)+height(root->right);
        
//         int ans = max(h1, max(h2, h3));
//         return ans;
//     }
    
//     pair<int, int> diameter(TreeNode* root){
//         // base case
//         if(root==NULL){
//             pair<int, int> p = make_pair(0, 0);
//             return p;
//         }
        
//         pair<int, int> left = diameter(root->left);
//         pair<int, int> right = diameter(root->right);
        
//         int op1 = left.first + 1;
//         int op2 = right.first + 1;
//         int op3 = left.second + right.second ;
        
//         pair<int, int> ans;
        
//         ans.first =  max(op2, max(op2, op3));
//         ans.second = max(left.second, right.second)+1;
        
//         return ans;
//     }
    
//     int diameterOfBinaryTree(TreeNode* root){
//         return diameter(root).first;
//     }
    
     int solve(TreeNode*root,int &ans){
        if(!root) return 0;
        int left = solve(root->left,ans);
        int right = solve(root->right,ans);
        int temp = 1+max(left,right);
        ans = max({ans,temp,1+left+right});
        return temp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans-1;  //here they have ask for edges
    }
};