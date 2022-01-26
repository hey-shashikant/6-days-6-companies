class Solution {
private:
    const int8_t pac = 0x01;
    const int8_t alt = 0x02;
    const int8_t bothOcean = 3;
    
    const int dir[5] = {0, 1, 0, -1, 0};
    
    int rMax;
    int cMax;
    
    bool inBound(int r, int c) {
        if (r < 0 || c < 0 || r > rMax || c > cMax) return false;
        return true;
    }
    
    void bfs(vector<vector<int>> &heights, vector<vector<int8_t>> &memo, queue<pair<int, int>> &bfsQ, int8_t ocean) {
        while (!bfsQ.empty()) {
            int currR = bfsQ.front().first;
            int currC = bfsQ.front().second;
            int currH = heights[currR][currC];
            
            bfsQ.pop();
            
            for (int i = 0; i < 4; i++) {
                int nextR = currR + dir[i];
                int nextC = currC + dir[i + 1];
                
                if (inBound(nextR, nextC) && !(memo[nextR][nextC] & ocean) && heights[nextR][nextC] >= currH) {
                    memo[nextR][nextC] |= ocean;
                    bfsQ.emplace(nextR, nextC);
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rSize = heights.size();
        int cSize = heights[0].size();
        
        vector<vector<int8_t>> memo (rSize, vector<int8_t>(cSize, 0)); // ocean count
        queue<pair<int, int>> bfsQ;
        
        vector<vector<int>> res;

        rMax = rSize - 1;
        cMax = cSize - 1;
        
        // Search pacific ocean side
        for (int c = 0; c < cSize; c++) {
            memo[0][c] |= pac;
            bfsQ.emplace(0, c);
        }
        
        for(int r = 0; r < rSize; r++) {
            memo[r][0] |= pac;
            bfsQ.emplace(r, 0);
        }
        
        // Perform BFS
        bfs(heights, memo, bfsQ, pac);
        
		// Search Atlantic ocen side
        for (int c = 0; c < cSize; c++) {
            memo[rMax][c] |= alt;
            bfsQ.emplace(rMax, c);
        }
        
        for (int r = 0; r < rSize; r++) {
            memo[r][cMax] |= alt;
            bfsQ.emplace(r, cMax);
        }
        
        bfs(heights, memo, bfsQ, alt);
        
        // count result
        for (int r = 0; r < rSize; r++) {
            for (int c = 0; c < cSize; c++) {
                if (memo[r][c] == bothOcean) {
                    res.push_back({r, c});
                }
            }
        }
        
        return res;
    }
};
