//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        vector<vector<int>> mat(n, vector<int>(n));
        for(int i = 0 ; i < n ; i++ )
            {
                for(int j = i+1 ; j < n; j++)
                    {
                        swap(matrix[i][j],matrix[j][i]);
                    }
            }
        for(int i = 0 ; i < n ; i++ )
            {
                int high = n - 1;
                int low = 0;
                while(low < high)
                    swap(matrix[low++][i] , matrix[high--][i]);
            }
            return;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends