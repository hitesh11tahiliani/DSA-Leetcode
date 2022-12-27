class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>n(nums.size());
        vector<int>m(nums.size());
        vector<int>ans(nums.size());
        n[0]=1;
        m[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++){
            n[i]=n[i-1]*nums[i-1];
        } 
        for(int i=nums.size()-2;i>=0;i--){
            m[i]=m[i+1]*nums[i+1];
        }
        for(int i=0;i<ans.size();i++){
         ans[i]=n[i]*m[i];
        }
        return ans;
    }
};