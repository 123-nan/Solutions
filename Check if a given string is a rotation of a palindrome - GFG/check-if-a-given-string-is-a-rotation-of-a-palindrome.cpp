//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int isRotatedPalindrome(string s)
	{
	    int n=s.length();
	   unordered_map<char,int>mp;
	   for(int i=0;i<n;i++)
	   {
	       mp[s[i]]++;
	   }
	   int odd=0;
	   for(auto it:mp)
	   {
	       if(it.second%2!=0)
	       odd++;
	   }
	   if(odd<=1)
	   return 1;
	   else
	   return 0;
	}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.isRotatedPalindrome(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends