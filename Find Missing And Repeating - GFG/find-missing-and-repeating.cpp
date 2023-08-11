//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
    int sum = 0;
    int s[n+1];
    for(int i = 0 ; i <= n ; i++){
        s[i] = 0;
    }
    vector<int>v;

    for(int i = 0 ; i < n ; i++){
        s[arr[i]]++;
    }
    
    int miss;
    
    for(int i = 1 ; i <= n ; i++ ){
        if(s[i] == 2){
            v.push_back(i);         
        }
        if(s[i] == 0)
            miss = i;
    }
    
    v.push_back(miss);
    return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends