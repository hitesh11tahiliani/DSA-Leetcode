class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ans = 0;
        while(!nums.empty()){
            int maxSum = INT_MIN;
            for(int i=0; i<nums.size(); i++){
                if(!nums[i].empty()){
                    int maxRow = *max_element(nums[i].begin(), nums[i].end());
                    maxSum = max(maxRow, maxSum);
                    nums[i].erase(find(nums[i].begin(), nums[i].end(), maxRow));
                    if(nums[i].empty()){
                        nums.erase(nums.begin()+i);
                        i--;
                    }
                }
                
            }
            ans += maxSum;
        }
        return ans;
    }
};