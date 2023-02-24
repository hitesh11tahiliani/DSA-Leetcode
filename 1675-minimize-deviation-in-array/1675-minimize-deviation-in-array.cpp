class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> maxH;
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(nums[i]%2==1){
                x*=2;
                maxH.push(x);
            }
            maxH.push(x);
            mini=min(mini,x);
        }
        int ans=INT_MAX;
        while(1){
            int a=maxH.top();
            ans=min(ans,(a-mini));
            if(a%2==0){
                maxH.pop();
                a/=2;
                mini=min(mini,a);
                maxH.push(a);
            }
            else break;
        }
        return ans;
    }
};