//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void rotate(int arr[] , int start , int end){
        while(start < end){
            swap(arr[start++] , arr[end--]);
        }
        return;
    }
    void leftRotate(int arr[], int n, int d) {
        rotate(arr , 0 , d-1);
        rotate(arr , d , n-1);
        rotate(arr , 0 , n-1);
        return;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}



// } Driver Code Ends