#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    class Element{
        public:
        int value,row,index;
        Element(int x,int y,int z)
        {
            value = x;
            row = y;
            index = z;
        }
    };
     struct comp{
       bool operator()(Element a,Element b)
        {
            return a.value>b.value;
        }
    };

    
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
         //code here
         int mini = INT_MAX, maxi = INT_MIN, range = INT_MAX;
         //priority_queue<Element,vector<Element>,comp> pq;
         priority_queue<Element,vector<Element>,comp> pq;
         int low, high;
         for(int i=0; i<k; i++)
         {
             Element e1 = Element(KSortedArray[i][0],i,0);
             pq.push(e1);
             maxi = max(maxi,KSortedArray[i][0]);
             mini = min(mini,KSortedArray[i][0]);
         }
         while(!pq.empty())
         {
             Element temp = pq.top();
             pq.pop();
             int tempmin = temp.value;
             if(range > (maxi - tempmin))
             {
                 mini = tempmin;
                 range = maxi - mini;
                 low = mini;
                 high = maxi;
             }
             if(temp.index == n-1)
             {
                 break;
             }
             temp.index = temp.index + 1;
             Element e1 = Element(KSortedArray[temp.row][temp.index],temp.row,temp.index);
             pq.push(e1);
             maxi = max(maxi,KSortedArray[temp.row][temp.index]);
         }
         return {low,high};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends
