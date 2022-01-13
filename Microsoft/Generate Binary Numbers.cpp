#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.

string solve(int n){
    string s = "";
    while(n != 0){
        s+=to_string(n%2);
        n/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}

vector<string> generate(int N)
{
	// Your code here
	vector<string>res;
	for(int i=1; i<=N; i++){
	    res.push_back(solve(i));
	}
	return res;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
