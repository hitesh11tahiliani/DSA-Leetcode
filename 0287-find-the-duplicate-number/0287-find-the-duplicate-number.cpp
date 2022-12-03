class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1, ans=0;
        
        while (i<j){
            if (nums[i]==nums[i+1]){
                ans = nums[i];
                break;
            }
            else if (nums[j]==nums[j-1]){
                ans = nums[j];
                break;
            }
            i++;
            j--;
        }
        return ans;
    }
};