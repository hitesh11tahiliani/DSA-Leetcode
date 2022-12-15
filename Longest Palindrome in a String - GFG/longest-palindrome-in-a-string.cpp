//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string str) {
        // code here
        string res = "";
        int maxlength = 1, start = 0, len = 0;
        for(int i = 0; i < str.length(); i++){
            int low = i-1;
            int high = i+1;
            
            while(high < str.length() && str[i] == str[high])
                high++;
            while(low >= 0 && str[i] == str[low])
                low--;
                
            while(low >= 0 && high < str.length() && str[low] == str[high]){
                low--;
                high++;
            }
            
             len = high-low-1;
            if(len > maxlength){
                maxlength = len;
                start = low+1;
            }
        }
        
        for(int i = start; i <= start+maxlength-1; i++)
            res+=str[i];
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends