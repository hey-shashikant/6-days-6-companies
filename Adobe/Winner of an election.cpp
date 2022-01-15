#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int>mp;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        string winner = arr[0];
        int score = mp[winner];
        for(int i=1; i<n; i++){
            string name = arr[i];
            int value = mp[arr[i]];
            if(value > score){
                winner = name;
                score = value;
            }
            else if(value == score){
                if(name < winner){
                    winner = name;
                    score = value;
                }
            }
        }
        string res = to_string(score);
        return {winner,res};
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends
