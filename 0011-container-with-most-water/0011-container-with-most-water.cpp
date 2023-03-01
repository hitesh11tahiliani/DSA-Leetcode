class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int i=0;
        int j= n-1;
        int maxi= INT_MIN;
        while(i<=j){
            maxi= max(min(height[i],height[j])*(j-i), maxi);
            if(height[i]<=height[j]) i++;
            else j--;
        }
        return maxi;
    }
};