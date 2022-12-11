class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        int n1=nums1.size();
         int n2=nums2.size();
         for(int i=0;i<n2;i++)
         {
             nums1.push_back(nums2[i]);
         }
         sort(nums1.begin(),nums1.end());
         int start=0;
         int end=nums1.size()-1;
         int mid=start+(end-start)/2;
         if(end%2==0)
         {
             ans=nums1[mid];
         }
         else
         {
             ans=nums1[mid]+nums1[++mid];
             ans=ans/2;
         }
         return ans;
    }
};