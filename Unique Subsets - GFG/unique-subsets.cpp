//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int>>res;
    set<vector<int>>temp;
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
       for(int i = 0 ; i < (1 << n) ; i++){  //2^n == 1<<n
            vector<int>v;
            for(int j = 0 ; j < n ; j++){
                if((1<<j) & i){
                    v.push_back(arr[j]);
                }
            }
            sort(v.begin() , v.end());
            temp.insert(v);
            
       }
       for(auto st : temp){
               res.push_back(st);
            }
       return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends