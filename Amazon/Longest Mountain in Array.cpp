class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int sz = arr.size();
        // base case
        if(sz <= 2){
            return 0;
        }
        int u = 0, d = 0, res = 0;
        char prev = '1';
        for(int i=1; i<sz; i++){
            int x = arr[i] - arr[i-1];
            if(x <= 0 and prev == '1'){
                continue;
            }
            else if(x > 0 and prev == '1'){
                // up = true;
                u++;
                prev = 'U';
            }
            else if(x > 0 and prev == 'U'){
                u++;
            }
            else if(x < 0 and prev == 'U'){
                d++;
                prev = 'D';
            }
            else if(x < 0 and prev == 'D'){
                d++;
            }
            else if(x > 0 and prev == 'D'){
                if(u != 0 and d != 0){
                    res = max(res,u+d+1);
                }
                u = 0; d = 0;
                u++;
                prev = 'U';
            }
            else if(x == 0){
                 if(u != 0 and d != 0){
                    res = max(res,u+d+1);
                }
                u = 0;
                d = 0;
                prev = '1';
            }
        }
        if(u != 0 and d != 0){
            res = max(res,u+d+1);
        }
        return res;
    }
};
