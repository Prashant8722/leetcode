//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
       vector<int>v; //for storing result
       set<int>s;   //storing every distinct element
       int n = nums.size(); //size of existing nums elemnt vector
       
       for(int i = 0 ; i < n ;i++ )
       {
           auto it = s.find(nums[i]);
           if(it == s.end()){    //if not exist element inserted into set
               s.insert(nums[i]);
           }
           else{                            
               s.erase(nums[i]);           //if duplicate existing element which is repeated only once will be removed into set
           }
       }
       //both element which is not repeated inserted into resultant vector
       v.push_back(*s.begin());         
       v.push_back(*++s.begin());
    
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends