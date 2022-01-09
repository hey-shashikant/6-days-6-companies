#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // The idea is to use bfs and traverse all the unrotten oranges.
        int row = grid.size(), col = grid[0].size();
        int fresh = 0, res = -1;
        vector<int>dir = {-1,0,1,0,-1};
        queue<pair<int,int>>pq;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    pq.push({i,j});
                }
            }
        }
        
        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                pair<int,int>t = pq.front();
                pq.pop();
                for(int i=0; i<4; i++){
                    int r = t.first + dir[i];
                    int c = t.second + dir[i+1];
                    if((r >= 0 and r < row) and (c >= 0 and c < col) and grid[r][c] == 1){
                        pq.push({r,c});
                        fresh--;
                        grid[r][c] = 2;
                    }
                }
            }
            res++;
        }
        if(res == -1){
            return 0;
        }
        if(fresh > 0){
            return -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
