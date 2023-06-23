//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int m,int n)
    {
       vector<vector<int>> res;
        set<long long int>s;
        
        for(int i = 0 ; i < m ;i++)
        {
            long long int dec = 0;
            
            for(int j = 0 ; j < n ;j ++)
                {
                    dec += M[i][j] * pow(2,j);
                }
                
            if(s.find(dec) == s.end())
                {
                   s.insert(dec);
                 //creting rows and inserting into directly res vecor
                   vector<int> row ;
                   for(int j = 0 ; j < n ; j++)
                   {
                    row.push_back(M[i][j]);
                   }
                   res.push_back(row);
                   
                }
                
        }
/*      for printing resultant matrix
        for(int i = 0 ; i < res.size() ;i++)
        {
            for(int j = 0 ; j < res[0].size() ;j ++)
                {
                    cout<<res[i][j]<<" ";
                }
            cout<<" ";
        }
*/
    return res;
}
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends