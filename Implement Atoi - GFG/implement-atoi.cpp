// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
  public:
    


    int atoi(string str) {
           //Your code here
           int result=0;
    int i=0;
    int sign=1;
    if(str[i]=='-'){
        sign=-1;
        i++;
    }
    while(str[i]){
        if(!(str[i]-'0'>=0 && str[i]-'0'<=9))
               return -1;
           result = result*10 + str[i]-'0';
           i++;
    }
       return result*sign;
       }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends