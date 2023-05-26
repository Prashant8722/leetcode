//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<int>res;

  public:
     void DFSRec(int i ,bool visited[], vector<int> adj[])
    {
        visited[i] = true;
        res.push_back(i);
        for(int u : adj[i])
            {
                if(!visited[u])
                {
                    DFSRec(u ,visited, adj);
                }
            }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        bool visited[v];
        for(int i = 0 ; i< v ; i++)
            visited[i] = false;
        
        for(int i = 0 ; i < v ; i++)
            {
                if(!visited[i])
                    DFSRec(i ,visited, adj);
            }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends