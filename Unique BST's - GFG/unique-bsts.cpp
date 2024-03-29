//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the total number of possible unique BST.
    long mod = 1e9+7;
    int numTrees(int n) 
    {
       long long dp[n+1];  // 0,1 ,2 ,,, n-1 , n
       dp[0] = 1;
       for(int i = 1 ; i<=n ; i++)
        {
            dp[i] = 0; 
            for(int j = 0 ; j < i ;j++)
            {
                dp[i] = (dp[i] % mod  +  ((dp[j] % mod ) * dp[i-j-1] % mod ) % mod) % mod; 
            }
        }
       return (int)dp[n];
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends