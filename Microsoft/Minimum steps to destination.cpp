// This a the recursive solution but it will result in TLE.
class Solution{
public:
    int solve(int src, int ctr, int dest){
        if(abs(src) > (dest)){
            return INT_MAX;
        }
        if(src == dest){
            return ctr-1;
        }
        int l = solve(src+ctr,ctr+1,dest);
        int r = solve(src-ctr,ctr+1,dest);
        return min(l,r);
    }
    int minSteps(int D){
        // code here
        int x = solve(0,1,D);
        return x;
    }
};


// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


/*
The logic behind this problem is that we keep adding the number till either we get our target of we hit greaer than target...
Now, let's take some examples.
D = 1 (1 steps)
D = 2 (1 + 2) which is greater than 2 now we keep adding element till sum > target and (sum-target)%2 == 0) because
       (1 + 2 + 3) here 6 - 4 = 2 so we will stop here... the logic here is if we turn +2 to -2 (1 -2 + 3) we will get 2...so we will be ultimately substracting 2*i from 
       out sum....
       
D = 3 (1+2)  = 3
D = 4 (1 + 2 + 3) -->> -1 + 2 + 3 i.e 3
*/
class Solution{
public:
    int minSteps(int D){
        // code here
        int steps = 0, sum = 0;
        while(true){
            sum = sum + steps;
            steps++;
            if(sum == D){
                return steps-1;
                break;
            }
            if(sum > D and (sum-D)%2 == 0){
                return steps-1;
                break;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
