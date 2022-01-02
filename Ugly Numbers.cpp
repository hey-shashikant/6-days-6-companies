
using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull dp[n+1] = {0};
	    dp[1] = 1;
	    ull i = 1, j = 1, k  = 1;
	    for(ull x=2; x<=n; x++){
	        ull x1 = dp[i]*2;
	        ull x2 = dp[j]*3;
	        ull x3 = dp[k]*5;
	        
	        ull minimum = min(x1,min(x2,x3));
	        dp[x] = minimum;
	        
	        if(minimum == x1){
	            i++;
	        }
	        if(minimum == x2){
	            j++;
	        }
	        if(minimum == x3){
	            k++;
	        }
	    }
	    return dp[n];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
