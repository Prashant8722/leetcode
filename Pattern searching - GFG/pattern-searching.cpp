//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*
s: string in which pattern we have to find pattern.
x: pattern needs to searched.
*/

bool searchPattern(string s, string x)
{
   for(int i = 0 ; i <= s.length() - x.length() ;i++ ){
        
        bool isBool = true;
        
        for( int k = 0 ; k < x.length() ; k++){
            if (x[k] != s[k+i]){
                isBool = false;
                break;
            }
        }
        
       if(isBool) 
            return true;
   }
   return false;
}



//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    
    while(t--)
    {
        string str, pat;
        cin>>str;
        cin>>pat;
        
        if(searchPattern(str, pat) == true)
            cout << "Present" <<endl;
        else cout << "Not present" <<endl;
    }
}


// } Driver Code Ends