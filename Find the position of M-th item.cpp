

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        // if the length of N == 1 then we have to handle explicitily the answer would
        // be 1 in that case
        if(N == 1){
            return 1;
        }
        // else check if the answer lies on the right hand side of the array
        // if it lies on right hand side then return the position
        int X = (M%N + K)-1;
        if(X <= N){
            return (M%N + K)-1;
        }
        //else return the modulus
        else{
            return X%N;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
}  // } Driver Code Ends
