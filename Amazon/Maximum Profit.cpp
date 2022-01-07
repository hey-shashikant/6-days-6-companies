O(N^3) solution.

// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        // code here
        if(n <= 1 or k == 0){
            return 0;
        }
        // int n = N;
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=k; i++){
            for(int j=1; j<n; j++){
                int m = dp[i][j-1], n = 0;
                for(int k=0; k<j; k++){
                    n = max(n,dp[i-1][k] + prices[j]-prices[k]);
                }
                dp[i][j] = max(m,n);
            }
        }
        return dp[k][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
