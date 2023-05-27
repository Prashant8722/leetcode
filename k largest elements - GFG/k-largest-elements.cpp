//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
    priority_queue<int, vector<int> , greater<int>> pq; // min-heap
    vector<int>res;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        int x = pq.top();
        if (x < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    //keep first k largest element in res vector
    for (int i = 0; i < k; i++)
    {
        res.push_back(pq.top());
        pq.pop();
    }
    reverse(res.begin() ,res.end() );
    return res;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends