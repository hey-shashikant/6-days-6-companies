#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int solve(vector<int>vec){
        vector<int>res;
        for(int i=0; i<vec.size(); i++){
            auto it = lower_bound(res.begin(),res.end(),vec[i]);
            if(it == res.end()){
                res.push_back(vec[i]);
            }
            else{
                *it = vec[i];
            }
        }
        return res.size();
    }
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0; i<M; i++){
            mp[B[i]]++;
        }
        vector<int>vec;
        for(int i=0; i<N; i++){
            if(mp.find(A[i]) != mp.end()){
                vec.push_back(A[i]);
            }
        }
        return (N+M) - 2*solve(vec);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends
