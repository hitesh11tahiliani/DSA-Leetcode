//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) 
    {
        // code here
        int left=0,right=c-1,up=0,down=r-1;
        vector<int>res;
        while(res.size()<(r*c)){
            for(int col=left;col<=right;col++){
                res.push_back(matrix[up][col]);
            }
            for(int row=up+1;row<=down;row++){
                res.push_back(matrix[row][right]);
            }
            if(up!=down){
            for(int col=right-1;col>=left;col--){
                res.push_back(matrix[down][col]);
            }}
            if(left!=right){
            for(int row=down-1;row>up;row--){
                res.push_back(matrix[row][left]);
            }}
            left++;
            right--;
            up++;
            down--;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends