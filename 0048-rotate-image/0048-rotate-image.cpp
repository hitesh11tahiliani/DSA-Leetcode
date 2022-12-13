class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
//         //first we take transpose of the matrix
//         for(int i = 0; i < n; ++i){
//             for(int j = i; j < n; ++j){
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
        
//         //then we take mirror image about the middle vertical line
//         for(int i = 0; i < n; ++i){
//             reverse(matrix[i].begin(), matrix[i].end());
//         }
        
		// complement of matrix 
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; ++i) {
		// 2 Pointer approach :  just like we do in 1D array we take left and right pointers
		// and swap the values and then make those pointers intersect at some point.
            int left = 0, right = n-1;
            while(left < right) {
                swap(matrix[i][left], matrix[i][right]);
                ++left;
                --right;
            }
        }
    }
};