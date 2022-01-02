// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        // The intution here can be we need to check four cases where the rectangle 
        // does not overlap. i.e either one rectangle lies on the top,left,right,or bottom
        // of each other
        int ans = 1;
        
        // if one rectangle lies on top of another
        if(L1[1] < R2[1]){
            ans = 0;
        }
        
        // if one rectangle lies on right of another
        if(R1[0] < L2[0]){
            ans = 0;
        }
        
        // if one rectangle lies on bottom of another
        if(R1[1] > L2[1]){
            ans = 0;
        }
        
        // if one rectangle lies on left of another
        if(L1[0] > R2[0]){
            ans = 0;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends
