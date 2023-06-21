//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {
       
        //code here 
        // tC == > O(3n) sc = ==>)(3n)
        long long int mul =1 ;
        vector<long long int> res;
        vector<long long int> left;
        vector<long long int> right;
        
        if(n == 1 ){
         res.push_back(1);
         return res;
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            mul = mul * arr[i];
            left.push_back(mul);
        }
        mul = 1;
         for(int i = n-1 ; i >= 0 ; i--)
        {
            mul = mul * arr[i];
            right.push_back(mul);
        }
        reverse(right.begin() , right.end());
        /*
        for(int i = 0 ; i < n ; i++)
        {
         cout<<left[i] << " "; 
        }
        cout << endl;
        for(int i = 0 ; i < n ; i++)
        {
         cout<<right[i] << " "; 
        }
        cout<<endl;
        */
        res.push_back(right[1]);
        for(int i = 1 ; i < n-1 ; i++)
            {
                long long int multi =left[i-1] * right[i+1];
                res.push_back(multi);
            }
            res.push_back(left[n-2]);
     return  res;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends