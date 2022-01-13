#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int row = 0, col = 0;
    vector<int>dir1 = {0,-1,0,1,0};
    vector<int>dir2 = {-1,-1,1,1,-1};
    //Function to find unit area of the largest region of 1s.
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c){
        visited[r][c] = 1;
        int ctr = 0;
        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty()){
            int r1 = q.front().first, c1 = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int x = r1 + dir1[i], y = c1 + dir1[i+1];
                if((x >= 0 and x < row ) and (y >= 0 and y < col) and grid[x][y] == 1 and visited[x][y] == 0){
                    q.push({x,y});
                    visited[x][y] = 1;
                }
            }
            for(int i=0; i<4; i++){
                int x = r1 + dir2[i], y = c1 + dir2[i+1];
                if((x >= 0 and x < row ) and (y >= 0 and y < col) and grid[x][y] == 1 and visited[x][y] == 0){
                    q.push({x,y});
                    visited[x][y] = 1;
                }
            }
            ctr++;
        }
        return ctr;
        
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        row = grid.size(), col = grid[0].size();
        int res = 0;
        // queue<pair<int,int>>q;
        vector<vector<int>>visited(row,vector<int>(col,0));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1 and visited[i][j] == 0){
                    res = max(res,dfs(grid,visited,i,j));
                    // q.push({i,j});
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
