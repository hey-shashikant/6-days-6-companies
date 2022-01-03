#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:

    string printMinNumberForPattern(string S){
        // code here 
        stack<int>stk;
        string res = "";
        int num = 1;
        for(int i=0; i<S.size(); i++){
            if(S[i] == 'D'){
                stk.push(num);
                num++;
            }
            else{
                stk.push(num);
                num++;
                while(!stk.empty()){
                    res+=to_string(stk.top());
                    stk.pop();
                }
            }
        }
        stk.push(num);
        while(!stk.empty()){
            res+=to_string(stk.top());
                    stk.pop();
        }
        return res;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
