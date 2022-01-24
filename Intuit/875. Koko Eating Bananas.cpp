class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size() >= h){
            return *max_element(piles.begin(),piles.end());;
        }
        else{
            long long low = 1,res = INT_MAX;
            long long high = *max_element(piles.begin(),piles.end());
            while(low <= high){
                long long mid = low + (high-low)/2;
                int ctr = 0;
                for(int i=0; i<piles.size(); i++){
                    ctr+=(piles[i] + mid - 1)/mid;
                }
                if(ctr <= h){
                    res = min(res,mid);
                    high = mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return res;
        }
    }
};
