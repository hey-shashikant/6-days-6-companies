#include <bits/stdc++.h>
using namespace std;

// first basic brute force approach can be to just sort the items of the array and 
// return the last 10 unique values from it whose TC : O(nlogn)
void solve()
{
    //Hello Cyborg Let the game begin...!!
    //code here.
    // given array
    int a[] = {10,2,3,4,1,2,3,4,5,6,7,5,4,3,4,5,6,3,2,3,4,1,22,1,22,3,44,5,67,54,23,11,12,34,56,78,90};
    int size = sizeof(a)/sizeof(a[0]);
    sort(a,a+size);
    for(int i = size-1; i>=size-11; i--){
        cout << a[i] << " ";
    }
    cout << "\n";
}

// second approach can be to use min heap and maintain a size of 10 for the heap
// TC : O(nlogk) where k = 10 in this case



void solve()
{
    //Hello Cyborg Let the game begin...!!
    //code here.
    // given array
    int a[] = {10,2,3,4,1,2,3,4,5,6,7,5,4,3,4,5,6,3,2,3,4,1,22,1,22,3,44,5,67,54,23,11,12,34,56,78,90};
    int size = sizeof(a)/sizeof(a[0]), k = 10;
    // sort(a,a+size);
    // set<int>st;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0; i<size; i++){
        if(pq.size() <= k){
            pq.push(a[i]);
        }
        else{
            pq.pop();
            pq.push(a[i]);
        }
    }
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}




int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
