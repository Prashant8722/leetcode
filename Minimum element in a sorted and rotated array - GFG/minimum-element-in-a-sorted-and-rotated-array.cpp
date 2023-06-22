//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        // Expected Time Complexity: O(log N).
        // Expected Auxiliary Space: O(log N). using binary search
        int l= 0 ; int r = n-1;
        int minimum = INT_MAX;
        while(l <= r)
        {
            //if array is aleady sorted in normal order means not rotated.
            if(arr[l] < arr[r])
                {
                    minimum= min(minimum , arr[l]);
                    return minimum;
                }
            //otherwise
            int mid = l + (r-l)/2;
            minimum = min(minimum , arr[mid]);
            //if array is rotated then first element is always less than the before first minimum element
            //search in right part of mid
            if(arr[mid]>= arr[0])
                {
                    l= mid +1;
                }
            else                //search in left part of mid
                r = mid - 1;
            
        }
        return minimum;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends