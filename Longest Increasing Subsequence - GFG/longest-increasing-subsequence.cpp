//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int ceilFun(vector<int>&arr , int low  , int high , int x)
    {
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] < x)
            {
                low  = mid + 1; 
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
   
    int longestSubsequence(int n, int a[])
    {

    // time complexity ===> O(n*long(n)) using ceil of binary search concept;
    // space complexity ===> o(n)
     vector<int> arr;
     arr.push_back(a[0]);
     int len = 1;
     for(int i = 1 ; i < n ;i++)
     {
         if(a[i] > arr[len -1])
            {
                 arr.push_back(a[i]);
                 len++;
            }
            else
            {
                int valid_ind =  ceilFun(arr , 0 , len-1 , a[i]);
                arr[valid_ind] = a[i];
            }
     }
     /*
     for(int i = 0 ; i < len ; i++)
     {
         cout<<arr[i] << " ";
     }
     */
     return len;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends