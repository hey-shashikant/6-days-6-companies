//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> v;
    void rec(string s,int n,int opened)
    {
        if(n!=0)
            rec(s+"(",n-1,opened+1);
        if(opened!=0)
            rec(s+")",n,opened-1);
        if(n==0 && opened==0)
            v.push_back(s);
    }
    vector<string> AllParenthesis(int n) 
    {
        rec("",n,0);
        return v;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
