//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int n) {
        int setpos = 0;
        bool flag = false;
        int res = 0;
      if( n  == 0){return -1;}
       while(n > 0)
       {
           if(n % 2 == 0)
           {
               setpos++;
           }
           else
           {
               if(flag != false) return -1; 
               res = ++setpos;
               flag = true;
           }
           n = n >> 1;
       }
       return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends