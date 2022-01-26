class Solution {
public:
    vector<int> findOrder(int nums, vector<vector<int>>& pre) {
        vector<int>adj[nums];
        vector<int>indegree(nums,0);
        for(auto &it : pre){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        vector<int>res;
        for(int i=0; i<nums; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto i : adj[node]){
                if(--indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        if(res.size() != nums){
            res.clear();
        }
        return res;
    }
};
