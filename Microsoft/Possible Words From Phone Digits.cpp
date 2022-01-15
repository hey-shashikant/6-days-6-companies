//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int a[], int N, int idx, string res, vector<string>& vec, unordered_map<int,string>& mp){
        if(idx >= N){
            vec.push_back(res);
            return;
        }
        string temp = mp[a[idx]];
        for(int i=0; i<temp.size(); i++){
            solve(a,N,idx+1,res+temp[i],vec,mp);
        }
        return;
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        unordered_map<int,string>mp;
        vector<string>vec;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        solve(a,N,0,"",vec,mp);
        return vec;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
