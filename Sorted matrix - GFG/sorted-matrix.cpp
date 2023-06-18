//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> v) {
        vector<int>vs;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                vs.push_back(v[i][j]);
            }
        }
        
         sort(vs.begin() , vs.end());
         for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                v[i][j] = vs[n*i + j];
            }
        }    
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends