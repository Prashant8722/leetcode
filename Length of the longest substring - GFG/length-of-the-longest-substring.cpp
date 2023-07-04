//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Time Com ==== (O(n^2)), we can minimize further to avoid TLE SC===>0(k) k==256
    int longestUniqueSubsttr(string s){
      
      int n = s.size(), res = 0;
      vector<int>prev(256 , -1);
      int i = 0; 
      
      for(int j = 0 ; j < n; j++){
        i = max(i , prev[s[j]] + 1);
        int maxEnd = j - i + 1;
        res = max(res , maxEnd);
        prev[s[j]] = j;
      }
      return res;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends