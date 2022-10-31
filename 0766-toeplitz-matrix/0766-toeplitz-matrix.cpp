class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int row = matrix.size();
        const int col = matrix[0].size();
        
        for (int i=1; i<row; i++){
            for (int j=1; j<col; j++){
                if(matrix[i][j]!=matrix[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
};