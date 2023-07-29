//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here
		    string ans="";
		    vector<char>v;
		    vector<int>vis(26,0);
		    
		    int n = a.length();
		    for(char c : a){
		    
		        if(!vis[c-'a']){
		            v.push_back(c);
		        }
		        vis[c-'a']++;
		        bool flag = false;
		        int m = v.size();
		        
		        for(int j = 0 ; j <  m ; j++){
		            if(vis[v[j]-'a'] == 1){
		                ans.push_back(v[j]);
		                flag = true;
		                break;
		            }
		        }
		        if(flag == false){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends