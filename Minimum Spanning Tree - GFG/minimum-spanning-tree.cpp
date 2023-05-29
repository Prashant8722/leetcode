//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	 //a[i][0] denotes that there is an edge between i and a[i][0][0] and second integer a[i][0][1] denotes that the distance between edge i and a[i][0][0] is a[i][0][1].
  /*  bool cmp(vector<int>&a , vecotr<int>&b)
    {
        return a[2] < b[2];
    }
    
    void makeset(vector<int>&parent ,vector<int>&rank , int v)
     {
    for(int i = 0 ; i < v ; i++)
    {
        parent[i]  = i ;
    }
     }
    
    
    int findparent(vector<int>&parent , int node)
    {
        if(parent[node] == node)
            return node
        return parent[node] = findparent(parent[node]);
    }
    
    void unionset(int u , int v  , vector<int>&parent , vector<int>&rank)
    {
        u = findparent(parent , u);
        v =findparent(parent , v);
        
        if(rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u ;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        sort(adj.begin() , adj.end() , cmp);
        vector<int>parent(v);
        vector<int>rank(v , 0);
        makeset(parent , rank , v);
        
        int minWeight = 0;
        
        for(int i = 0 ; i < adj.size() ; i++){
            int u = findparent(parent , adj[i][0]);
            int v = findparent(parent , adj[i][1]);
            int wt = adj[i][2];
            
            if(u != v)
            {
                minWeight+=wt;
                unionset(u , v , parent , rank)
            }
            
        }
        
        
    }
    */
    // Find function for DSU
int find(vector<int>& parent, int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent, parent[x]);
}

// Union function for DSU
void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rep_x = find(parent, x);
    int rep_y = find(parent, y);
    
    if (rank[rep_x] < rank[rep_y])
        parent[rep_x] = rep_y;
    else if (rank[rep_x] > rank[rep_y])
        parent[rep_y] = rep_x;
    else {
        parent[rep_y] = rep_x;
        rank[rep_x]++;
    }
}

int spanningTree(int v, vector<vector<int>> adj[]) {
    // Initialize DSU
    vector<int> parent(v);
    vector<int> rank(v, 0);
    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    int MSTWeight = 0;  // Total weight of the MST

    // Create vector to store all edges
    vector<pair<int, pair<int, int>>> edges;

    // Construct the edges vector
    for (int u = 0; u < v; u++) {
        for (auto e : adj[u]) {
            int dest = e[0];
            int wt = e[1];
            edges.push_back({wt, {u, dest}});
        }
    }

    // Sort the edges in non-decreasing order
    sort(edges.begin(), edges.end());

    // Process each edge
    for (auto edge : edges) {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // Check if adding the edge creates a cycle
        if (find(parent, u) != find(parent, v)) {
            MSTWeight += wt;
            unionSet(parent, rank, u, v);
        }
    }

    return MSTWeight;
}

};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends