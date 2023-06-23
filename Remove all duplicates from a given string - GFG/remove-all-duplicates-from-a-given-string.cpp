//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	   unordered_set<char>s;
	   int len = str.length();
	   int i = 0;
	   string res = "";
	   while(len > i)
	   {
	       auto it = s.find(str[i]);       
	       if(it == s.end()){
	            s.insert(str[i]);
	            res+=str[i];
	       }
	       i++;
	   }
	
	   return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends