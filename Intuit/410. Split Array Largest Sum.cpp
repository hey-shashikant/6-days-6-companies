class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int s=0,e=0;
        
        // min value that can be returned is MAX value in array i.e when m=size of nums. start=minValue
        // max value that can be returned is SUM of all elements in the array, when m=1. end = maxValue
        //apply binary search in the range [start, end], as the potential ans lies in b/w it.
        
        for(int i=0;i<nums.size();i++){
            s = max(s,nums[i]);
            e += nums[i];
        }
        
        while(s<e){
            int mid = s + (e-s)/2;
            
            // count no. of pieces nums can be divided into
            // such that the sum is less than mid (the potential ans)
            int sum=0;
            int count=1;
            
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i] > mid){
                    sum = nums[i];
                    count++;
                } else{
                    sum += nums[i];
                }
            }
            
            // check if no. of pieces that we could divided is <= the allowed no. of pieces
            // if "<=" , this was due to we are considering mid (potential ans) to be large
            // so reduce end to mid;
            if(count <= m){
                e=mid;
            } else{
                s=mid+1;
            }
        }
        return e;
    }
};
