// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        // Here we can maintain 2 stacks one for storing the integers 
        // and other for storing the characters or '[' and ']'
        stack<int>store_int;
        stack<char>store_char;
        string result = "", temp = "";
        for(int i=0; i<s.size(); i++){
            
            // if it is a number
            int ctr = 0;
            if(s[i] >= '0' and s[i] <= '9'){
                while(s[i] >= '0' and s[i] <= '9'){
                    ctr = ctr*10 + s[i] - '0';
                    i++;
                }
                store_int.push(ctr);
                i--;
            }
            
            // if we encounter '[' then
            
            else if(s[i] == ']'){
                int count = 0;
                temp = "";
                if(!store_int.empty()){
                    count = store_int.top();
                    store_int.pop();
                }
                // temp = "";
                while(!store_char.empty() and store_char.top() != '['){
                    temp = store_char.top() + temp;
                    store_char.pop();
                }
                if(!store_char.empty()){
                    store_char.pop();
                }
                
                for(int j=0; j<count; j++){
                    result = result + temp;
                }
                
                for(int j=0; j<result.size(); j++){
                    store_char.push(result[j]);
                }
                
                result = "";
            }
            else if(s[i] == '['){
                if(s[i-1] >= '0' and s[i-1] <= '9'){
                    store_char.push(s[i]);
                }
                else{
                    store_char.push(s[i]);
                    store_int.push(1);
                }
            }
            else{
                store_char.push(s[i]);
            }
        }
        // string s1 = "";
        while(!store_char.empty()){
            result = store_char.top() + result;
            store_char.pop();
        }
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
