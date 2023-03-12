//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool matching(char t , char b)
        {
            return (t == '(' && b==')' || t=='{' && b =='}' || t=='[' && b==']');
        }
    bool ispar(string x)
    {
        stack<char>s;
        for(int i = 0 ; i < x.length() ; i++){
            char p = x[i];
            if(p == '(' || p=='{' || p == '[')
                s.push(p);
            else
                {
                    if(s.empty() == true)
                        return false;
                    else if(matching(s.top() , p) == false)
                        return false;
                    else
                        s.pop();
                }
        }
        return (s.empty() == true);
        }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends