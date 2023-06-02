//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int , int>m;
        int count = 0;
        int res = 0;
        int div = ceil(n/k) + 1;
        for(int i = 0 ; i < n ;i++)
        {
            m.insert({arr[i] , m[arr[i]]++});
        }
        for(auto it = m.begin() ; it != m.end() ; it++)
        {
            if(it->second >= div)
                res++;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends