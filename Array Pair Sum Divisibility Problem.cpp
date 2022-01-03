
 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int>mp;
        int n = nums.size(), ctr = 0;
        if(n%2 != 0){
            return false;
        }
        for(int i=0; i<nums.size(); i++){
            int x = nums[i]%k;
            int y = k - x;
            if(y == k){
                if(mp.find(0) != mp.end() and mp[0] > 0){
                    ctr++;
                    mp[0]--;
                    mp[x]--;
                }
            }
            else if(mp.find(y) != mp.end() and mp[y] > 0){
                ctr++;
                mp[x]--;
                mp[y]--;
            }
            mp[x]++;
        }
        return ctr == n/2;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
