#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}


 // } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */



class Solution{
 public:
   vector<int> find3Numbers(vector<int> a, int n) {
       stack<int> s;
       for(int i=n-1;i>=0;i--){
           while(!s.empty()&&s.top()<=a[i])//Pop the elements that are smaller than current number
           s.pop();    
           s.push(a[i]); //push every element since it will always be smaller than stacks top
           if(s.size()==3)break;   //we found answer
       }
       vector<int> ans;
       while(!s.empty()){
           ans.push_back(s.top());
           s.pop();
       }
       if(ans.size()!=3)return {}; // when we don't get three numbers
       return ans;
   
   }
};

// { Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}  // } Driver Code Ends
