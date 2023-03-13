//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string reverseEqn (string s)
        {
            stack<string>st;
            int i = 0 ; 
            int len =s.length();
            while(len>0)
            {   
                string mat="";
                if(s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/')
                    {
                        mat +=s[i++];
                        len--;
                    }
                else{
                while(s[i] != '-' && s[i] != '+' && s[i] != '*' && s[i] != '/' && len > 0){
                    mat = mat+s[i++];
                    len--;
                    }
                }
                st.push(mat);
            }
            string sk = "";
            while(!st.empty()){
                sk = sk + st.top();
                st.pop();
            }
            return sk;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends