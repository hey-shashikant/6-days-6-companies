#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int>mp;
		    queue<char>pq;
		    string res = "";
		  //  list<char>pq;
		    for(int i=0; i<A.size(); i++){
		        mp[A[i]]++;
		      //  pq.push(A[i]);
		        if(mp[A[i]] == 1){
		            pq.push(A[i]);
		        }
		        while(!pq.empty() and mp[pq.front()] > 1){
		            pq.pop();
		        }
		        if(pq.size() == 0){
		            res+='#';
		        }
		        else{
		            res+=pq.front();
		        }
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
