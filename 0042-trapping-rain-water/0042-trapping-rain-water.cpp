class Solution {
public:
    /*
    Approach is simple at any building if we know the max height building in left of it and max height
	building in the right of it then we can calculate how much water will be stored at current building i.e
	min(left,right) height - height[i]
    */
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n); //array to store max height in the left of i
        vector<int> right(n); //array to store max height in the right of i
        int ans = 0,h;
        
        
        left[0] = height[0];
        right[n-1] = height[n-1];
        
        for(int i=1 ; i<n ; i++)
            left[i] = max(height[i],left[i-1]);
        
        for(int i=n-2 ; i>=0 ; i--)
            right[i] = max(height[i],right[i+1]);
        
        //at any building the stored water = min(left,right) height - current height
        for(int i=0 ; i<n ; i++) {
            h = min(left[i],right[i]);
            if(h > height[i])
                ans += h-height[i];
        }
        return ans;
    }
};