#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string res = "", temp = "";
        res+=tolower(s[0]);
        for(int i=1; i<s.size(); i++){
            if(isupper(s[i])){
                res+=temp;
                res+=' ';
                temp = "";
                char ch = tolower(s[i]);
                temp+=ch;
            }
            else{
                temp+=s[i];
            }
        }
        res+=temp;
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends
