//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> ans;    //resultant topological sort will be stored.
	    queue<int>q;        //queue in which 0 degree vertices will be pushed 
	    
	    vector<int>indegree(v,0);
	    //Adding indegree of every vertices;
	    for(int i =0; i < v; i++)
	    {
	        vector<int>data = adj[i];
	        for(auto x : data)
	            {
	                indegree[x]++;
	            }
	    }
	    //check which indegree is zero initially and pushed into queue
	    for(int i =0; i < v; i++)
	    {
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	   // just like bfs 
	    while(!q.empty())
	    {
	        int u = q.front();
	        q.pop();
	        ans.push_back(u);
	
	        for(auto v : adj[u])
	        {           //adjacent of vertices u will be reduced and checked if indegree of v
	            indegree[v]--;               
                if(indegree[v] == 0)        // is 0 then pushed into queue
                    q.push(v);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends