//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // Initialize minimum and maximum values
        int minimum = matrix[0][0];
        int maximum = matrix[0][c-1];
       
    // Find the minimum and maximum values in the first row 
        for(int i = 1 ; i < r ; i++){
            if(minimum > matrix[i][0]) minimum = matrix[i][0];
            if(maximum < matrix[i][c-1]) maximum = matrix[i][c-1]; 
        }
        
        // Calculate the position of the median
        int medpos = (r * c + 1) / 2;
        
        // Perform binary search to find the median
        while(minimum < maximum){
        // Calculate the middle element
            int mid = (minimum + maximum )/ 2;
            int midpos = 0; 
            
      // Count the number of elements less than or equal to mid in each row

            for(int i = 0 ; i < r ; i++){
            
            // Use upper_bound to find the first element greater than mid
            // Subtracting the beginning iterator from the upper_bound result gives the count
                midpos += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            // Adjust the search range based on the position of the median
            if(midpos < medpos)     
                minimum = mid + 1;  // The median is in the upper half
            else
                maximum = mid;      // The median is in the lower half
                
        }
        return minimum; //Return the median
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends