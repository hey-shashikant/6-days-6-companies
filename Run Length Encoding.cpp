#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string res = "";
  for(int i=0; i<src.size(); i++){
      char ch = src[i];
      int ctr = 0;
      res+=ch;
      int j = i;
      while(j < src.size() and src[j] == ch){
        //   if(src[i] == ch){
              j++;
              i++;
              ctr+=1;
      }
      string s1 = to_string(ctr);
    //   cout << ctr << "\n";
    //   char ch1 = char(ctr);
      res+=s1;
      i--;
  }
  return res;
}     
 
