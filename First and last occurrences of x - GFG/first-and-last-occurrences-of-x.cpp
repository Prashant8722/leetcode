//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int l = 0;
    int r = n-1;
    vector<int>res(2 , -1);
    int first;
    while( l <= r)
    {
       int m = l + (r - l)/2;
 
        if(arr[m] >= x)
            r = m -1;
        else
        {
            l = m+1;
        }
    }
    if(arr[l] == x)
    {
        res[0] = l;
    }
    else
        return res;

    for(int i = l+1 ; i < n ; i++)
    {
    if(arr[i-1] != arr[i])
        {
            res[1] = i-1;
            break;
        }
        if(i == n-1 && x == arr[i]) res[1] = i;
    }
    if(l == n-1) res[1] = l;
    return res;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends