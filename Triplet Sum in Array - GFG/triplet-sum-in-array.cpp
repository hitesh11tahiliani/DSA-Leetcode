//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
   {
       //Your Code Here
       //first sort the array
       sort(A, A + n);
       for(int i = 0; i < n; i++){
           int left = i + 1;
           int right = n - 1;
           while(left < right){
               if(A[i] + A[left] + A[right] == X)
                   return true;
               else if(A[i] + A[left] + A[right] > X)
                   right--;
               else 
                   left++;
           }
       }
       return false;
   }
};

// [1 4 45 6 10 8]
// 13 

// 1 4 6 8 10 45 


//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends