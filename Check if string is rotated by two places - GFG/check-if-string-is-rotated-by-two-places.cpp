//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1.length() == 1 && str2.length() == 1 && str1 == str2) return true;
        if(str1.length() == 1 && str2.length() == 1 && str1 != str2) return false;
        string res = "";
        for(int i = 2 ; i < str1.length() ; i++){
            res = res + str1[i];
        }
        for(int i = 0; i < 2 ; i++){
            res += str1[i];
        }
        
        string strres = "";
        for(int i = str1.length() - 2 ; i < str1.length() ; i++){
            strres = strres + str1[i];
        }
        for(int i = 0; i < str1.length() - 2  ; i++){
            strres += str1[i];
        }
        if(res == str2 || strres == str2) return true;
        return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends