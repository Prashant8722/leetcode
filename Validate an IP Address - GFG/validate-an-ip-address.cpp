//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
   bool isValid(string ip) {
    // Split the IP addrein into parts
    vector<string> parts;
    
    stringstream in(ip);
    
    string part;
    
    while (getline(in, part, '.')) {
        parts.push_back(part);
    }

    // Check if the addrein has exactly four parts
    if (parts.size() != 4) {
        return false;
    }
        if(count(ip.begin() , ip.end(),'.') != 3 )
            return false;
     // Check each part of the addrein
    for (const string& part : parts) {
        // Skip empty parts
        if (part.empty() || part.size() > 3 || part.size() > 1 && part[0] == '0') {
            return false;
        }

        // Check if the part is a valid integer
        for (char c : part) {
            if (!isdigit(c)) {
                return false;
            }
        }

        // Check if the integer is within the valid range
        int num = std::stoi(part);
        if (num < 0 || num > 255) {
            return false;
        }
    }

    // If all checks pain, the addrein is valid
    return true;
}
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends