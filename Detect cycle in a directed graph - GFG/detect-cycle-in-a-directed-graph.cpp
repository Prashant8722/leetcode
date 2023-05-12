//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
   bool  DFSCycle(int s , vector<int> adj[] , vector<bool>&visited , vector<bool>&currvisited)
    {
        visited[s] = true;
        currvisited[s] = true;
        
        for(auto x : adj[s]){
            if(!visited[x]){
                if(DFSCycle(x ,adj , visited , currvisited))
                    return true;
            }
            else if(visited[x] == true && currvisited[x] == true)
                return true;
        }
        currvisited[s] = false;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        vector<bool> visited(v , false) , currvisited(v,false);
        
        for(int i = 0 ; i< v ; i++){
                if(!visited[i]){
                    if(DFSCycle(i , adj , visited , currvisited))
                        return true;
             }
            }
            return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends