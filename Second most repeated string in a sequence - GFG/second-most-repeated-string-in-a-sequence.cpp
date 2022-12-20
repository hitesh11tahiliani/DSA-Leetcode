//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map <string, int> m;
    
        for (int i = 0; i < n; ++i)
            m[arr[i]]++;
    
    
        // first and second most occurred strings
        int mx1 = INT_MIN, mx2 = INT_MIN;
    
        for (auto i : m)
        {
            // we got a new mx1
            // hence, current mx1 is stored in mx2
            if (i.second > mx1)
            {
                mx2 = mx1;
                mx1 = i.second;
            }
    
            // we got a new mx2 second largest comes after first largest
            else if (i.second > mx2)
            {
                mx2 = i.second;
            }
        }
        
        for (auto i : m)
            if (i.second == mx2)
                return i.first;
        
        return "";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends