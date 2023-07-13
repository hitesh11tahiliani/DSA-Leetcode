class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& a) {
        vector<vector<int>> nums(m,vector<int> (n,0));
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<2;j++){
                if(j) col[a[i][j]]++;
                else row[a[i][j]]++;
            }
        }
        
        for(auto x : row){
            for(int i=0;i<n;i++){
                nums[x.first][i] += x.second;
            }
        }
        for(auto x : col){
            for(int i=0;i<m;i++){
                nums[i][x.first] += x.second;
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j] % 2 != 0) count++;
            }
        }
        return count;
    }
};