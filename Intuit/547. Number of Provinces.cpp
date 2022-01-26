class Solution {
public:
    int n=0;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int connectedComponent = 0;
        n = isConnected.size();
        vector<int> visited(n,0);
        
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                connectedComponent+=1;
                dfs(i,isConnected, visited);
            }
        }
        return connectedComponent;
    }
    
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited){
        if(visited[node] == 1) return;
        
        visited[node] = 1;
        for(int i=0; i<n; i++){
            if(i != node && isConnected[node][i] == 1){
                dfs(i, isConnected, visited);
            }
        }
    }
};
