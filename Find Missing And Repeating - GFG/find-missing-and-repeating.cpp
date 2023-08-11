//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int>v;
     for (int i = 0; i < n; ) {
        if (arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        } else {
            i++;
        }
    }
     for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            v.push_back(arr[i]);
            v.push_back(i + 1);
            break;
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