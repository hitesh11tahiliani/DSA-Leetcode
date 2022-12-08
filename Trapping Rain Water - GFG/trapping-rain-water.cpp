//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        // int n = height.size();
        vector<int> left(n); //array to store max height in the left of i
        vector<int> right(n); //array to store max height in the right of i
        long long ans = 0,h;
        
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        
        for(int i=1 ; i<n ; i++)
            left[i] = max(arr[i],left[i-1]);
        
        for(int i=n-2 ; i>=0 ; i--)
            right[i] = max(arr[i],right[i+1]);
        
        //at any building the stored water = min(left,right) height - current height
        for(int i=0 ; i<n ; i++) {
            h = min(left[i],right[i]);
            if(h > arr[i])
                ans += h-arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends