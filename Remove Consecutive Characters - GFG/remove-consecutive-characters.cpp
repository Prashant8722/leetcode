//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        string s = "";int len= S.size();
        s +=S[0];
        int i = 1 ;
        while(i < len)
        {
            if(S[ i - 1 ] != S[i])
                s+=S[i];    
            i++;
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends