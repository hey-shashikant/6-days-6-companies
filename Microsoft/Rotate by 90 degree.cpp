//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
 
void print(vector<vector<int> >& matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    for(int i=0; i<row; i++){
        for(int j=0; j<i; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
 
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    // The idea here is to first transpose the matrix then swap the matrix rowwise..
    // i.e first row with the last row then second row with the second last row and
    // so on.....
    int row = matrix.size(), col = matrix[0].size();
    for(int i=0; i<row; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    // print(matrix);
    int i = 0, j = row - 1;
    while(i < j){
        swap(matrix[i],matrix[j]);
        i++;
        j--;
    }
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
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends
