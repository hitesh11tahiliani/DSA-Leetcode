// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
//         vector<int> ans;
        
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
        
//         int j=0;
        
//         for (int i=0; i<nums1.size(); i++){
//             if (nums1[i]==nums2[j]){
//                 if(ans[ans.size()-1]==nums1[i]){
//                     i++;
//                 }
//                 ans.push_back(nums1[i]);
//                 j++;
//             }
//             else if(nums1[i]>nums2[j]){
//                 j++;
//             }
//             else{
//                 i++;
//             }
//         }
    
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //two pointer approach
        
        //arrays are sorted so that we can use two pointer approach
        
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        
        //set is used becasue we have to return only unique elements
        set<int>s;
        
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]>nums2[j]) j++;
            
            
            //whichever element is smaller(ith or jth) is increased, as arrays are sorted
            // so if high value index is moved than we can miss some less value elemets,
            // so avoiding this less value element's index is moved.
            
            
            else if(nums1[i]<nums2[j]) i++;
            
            //elements are inserted in sets so that only unique value is stored
            else{
                s.insert(nums1[i]);
                i++;
                j++;
            }
        }
        
        
        //unique elements(from set) are getting stored in vector as return type is vector
        vector<int>ans;
        for(auto i : s) ans.push_back(i);
        
        //returning vector
        return ans;
    }
};