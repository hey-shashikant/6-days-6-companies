#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    bool dfs(int src, int dest, vector<int>& vis, vector<int>adj[]){
        if(src == dest){
            return true;
        }
        vis[src] = 1;
        for(int i : adj[src]){
            if(!vis[i]){
                if(dfs(i,dest,vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
    
    int isBridge(int V, vector<int> arr[], int c, int d) 
    {
        // Code here
        vector<int>adj[V];
        for(int i=0; i<V; i++){
            for(auto j : arr[i]){
                if((i == c and j == d) or (i == d or j == c)){
                    continue;
                }
                else{
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>vis(V,0);
        if(dfs(c,d,vis,adj)){
            return 0;
        }
        return 1;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
