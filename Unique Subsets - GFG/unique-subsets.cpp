//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int>> res;

void generateSubsets(vector<int>& arr, int index, vector<int>& current) {
    res.push_back(current);

    for (int i = index; i < arr.size(); i++) {
        if (i > index && arr[i] == arr[i - 1]) {
            continue; // Skip duplicate elements
        }
        current.push_back(arr[i]);
        generateSubsets(arr, i + 1, current);
        current.pop_back();
    }
}

vector<vector<int>> AllSubsets(vector<int> arr, int n) {
    sort(arr.begin(), arr.end()); // Sort the array

    vector<int> current;
    generateSubsets(arr, 0, current);

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