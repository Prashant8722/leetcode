//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
   int left_bracket = 0;
   int right_bracket = 0;
   if( s.size() % 2 != 0) return -1;
  for(char c : s){
            if(c == '{'){
            left_bracket++;
       }
        else {
            if(left_bracket == 0)
                right_bracket++;
            else
            {
                left_bracket--;
            }
            
        }     
   }
   int ans =  ceil(left_bracket / 2.0) + ceil(right_bracket / 2.0); 
   return ans;
}