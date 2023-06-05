//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
   
   int maxSumIS(int a[], int n)  
	{  
    // time complexity ===> O(n*log(n)) using ceil of binary search concept;
    // space complexity ===> o(n)
    
     vector<int> arr;
     
     for(int i = 0 ; i < n ;i++)
     {
         arr.push_back(a[i]);
         for(int j = 0 ; j < i ; j++){
         if(a[i] > a[j])
            {
                 arr.pop_back();
                 arr.push_back(max(arr[i] , a[i]+arr[j]));
            }
     }
    }
     int sum =arr[0];
     for(int i = 1 ; i < arr.size() ; i++)
     {
         sum =max(sum , arr[i]);
     }
     
    //   for(int i = 0 ; i < arr.size() ; i++)
    //  {
    //      cout<< arr[i] << " ";
    //  }
    //  cout <<endl;
     return sum;
    }
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends