//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){

    sort(a.begin() , a.end());
    // for(auto c : a)
    // {
    //     cout<<c<<" ";
    // }
    // cout<<endl;
    long long minimum = a[m-1] - a[0];
    
    for(int i = 1 ; i <= n-m ; i++){
        long long diff = a[m-1+i] - a[i];
            if(diff <= minimum)
                     minimum = diff;
            // cout<<a[i]<<" " << a[m-1+i]<<" ";
            }
        return minimum;
    }
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends