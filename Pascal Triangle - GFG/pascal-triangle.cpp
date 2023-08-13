//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
#define ll long long
#define mod 1000000007;
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
    vector<vector<ll>> temp(2, vector<ll>(n, 1));

    for (int i = 2; i < n; i++) {
        for (int j = 1; j < i; j++) {
            temp[i % 2][j] = (temp[(i - 1) % 2][j - 1] + temp[(i - 1) % 2][j]) % mod;
        }
    }

    return temp[(n - 1) % 2];
}
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends