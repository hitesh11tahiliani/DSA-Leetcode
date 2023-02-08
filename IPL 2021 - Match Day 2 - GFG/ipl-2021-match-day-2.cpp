//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> a, int n, int k) {
        list<int> ans;
        vector<int> aa;
        int maxx=INT_MIN;
        for(int i=0;i<k;i++)
        {
            maxx=max(maxx,a[i]);
            ans.push_back(a[i]);
        }
        aa.push_back(maxx);
        for(int i=k;i<n;i++)
        {
            ans.push_back(a[i]);
            int temp=ans.front();
            ans.pop_front();
            if(temp==maxx&&a[i]<maxx)
            {
                int maxxx=0;
                for(auto j:ans)
                {
                    maxxx=max(maxxx,j);
                }
                maxx=maxxx;
            }
            else
            {
                maxx=max(maxx,a[i]);
            }
            aa.push_back(maxx);
        }
        return aa;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends