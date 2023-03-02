//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long mini = INT_MAX;
        long long l=0, r=m-1;
        while(r<n){
            long long diff = a[r]-a[l];
            mini = min(mini,diff);
            l++; r++;
        }
        return mini;
    }   
};

// {3, 4, 1, 9, 56, 7, 9, 12}
//  1 3 4 7 9 9 12 56 
 
//  {7, 3, 2, 4, 9, 12, 56}
//  2 3 4 9 7 12 56 

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends