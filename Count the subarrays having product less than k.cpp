#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        // The intution for this problem is we will keep iterating through the
        // array and perform the product and once the product is more than
        // k we will start removing elements from the start of the array
        long long int i = 0, j = 0, ctr = 0, product = 1;
        while(j < n){
            product*=a[j];
            // if the product is more than k then start removing elemnets
            while(i < n and product >= k){
                product/=a[i];
                i++;
            }
            // j++;
            if(product < k){
                ctr+=(j-i)+1;
            }
            j++;
        }
        return ctr;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
