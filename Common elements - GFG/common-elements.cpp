//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int>res;
            //Initialize three pointers, one for each array: i for array A, j for array B, and k for array C
            int i = 0 , j = 0 , k = 0;
            int prev_ele = INT_MIN;
            while(i < n1 && j < n2 && k < n3)
            {
                //If all three elements are equal, we have found a common element.store the element.
                if(A[i] == B[j] && B[j] == C[k]){
                    if(A[i] != prev_ele){
                    res.push_back(A[i]);
                    prev_ele = A[i];
                    }
                    i += 1;
                    j += 1;
                    k += 1;
                }
                //If the element at A[i] is smaller than either B[j] or C[k], move the pointer i to the next element in array A.
                else if(A[i] < B[j] || A[i] < C[k])
                    i++;
                // If the element at B[j] is smaller than either A[i] or C[k], move the pointer j to the next element in array B.
                else if(B[j] < A[i] || B[j] < C[k])
                    j++;
                // If the element at C[k] is smaller than either A[i] or B[j], move the pointer k to the next element in array C.
                else
                    k++;
            }
            return res;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends