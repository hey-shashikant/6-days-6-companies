class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
      int n = points.size();
      int cnt=0,tmp=0;
      for(int i=0;i<n;++i){
        unordered_map<int,int> m;
        for(int j=0;j<n;++j){
          if(j==i) continue;
          tmp = pow(points[i][0]-points[j][0],2) + pow(points[i][1]-points[j][1],2);
          m[tmp]++;
        }
        for(auto &[key,value]:m)  cnt+= value*(value-1); //C(n,2)
      }
      return cnt;
    }
};
