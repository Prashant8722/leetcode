//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    sort(arr, arr+size);
    int i  = 0;
    int j = 1;
    while(i < size &&  j < size )
    {
        int temp = arr[j] - arr[i] ;
        if(temp == n && i != j) //i==j means only one element diff = 0 which is not correct because we need 2 elements for difference
            return true;
        else if(temp >  n ) //differnce jada to i++ bcz decreasing diff by inc i;
            i++;
        else
            j++;            //differnce kam to j++ bcz gap more b/w two elemments due to sorting order inc j by 1;
    }
    return false;
    
}