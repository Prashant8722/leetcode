//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int>st;
        int c;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '*' || s[i] == '/' ||s[i] == '+' || s[i]=='-'){
                int b = st.top() ; 
                st.pop();
                int a = st.top();
                st.pop();
                if(s[i] == '*')
                    c = a*b;
                else if(s[i] == '/')
                    c = a/b;
                else if(s[i] == '+')
                    c = a+b;
                else if(s[i] == '-')
                    c = a-b;
                st.push(c);
            }
            else
            {
                st.push(int(s[i]) - 48);
            }
        }
        c = st.top();
        return c;
       
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends