//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
        int getCount (string S, int N)
        {
            int count[26] = {0};
            int counter = 0, i = 1 ; 
            int len = S.length() - 1;
           while(len-- > 0)
           {
               if(S[i]-'a' != S[i-1]-'a'){
                    count[S[i-1]-'a']++;
           }
            i++;
           }
           count[S[i-1]-'a']++;
           for(int i = 0 ; i < 26 ; i++){
                if(count[i] == N)
                    counter++;
           }
        //   for(int i = 0 ; i < 26 ; i++){
        //       cout<<count[i] << " ";
        //   cout<<endl;
        //   }
           return counter;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n; cin >> n;
        
        Solution ob;
        cout <<ob.getCount (s, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends