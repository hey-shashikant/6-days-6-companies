class Solution {
public:
    bool isValid(vector<int>& weights, int days,int mid){
        int wt=0;
        int d=1;
        for(int i=0;i<weights.size();i++){
            wt+=weights[i];
            if(wt>mid){
                d++;
                wt=weights[i];
            }
            if(d>days){
                return false;
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=0;
        int low=INT_MIN,high=0;
        for(auto it : weights){
            low=max(low,it);
            high+=it;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(weights,days,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
