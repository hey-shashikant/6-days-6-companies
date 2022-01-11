#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        // The approach here is to traverse the array first from left to right
        // then from top to bottom, then from right to left and finally from
        // bottom to top until left <= right and top <= bottom....
        int left = 0, right = c - 1, top = 0, bottom = r - 1, ctr = 0;
        vector<int>vec;
        while(left <= right and top <= bottom){
            if(ctr == 0){
                for(int i=left; i<=right; i++){
                    vec.push_back(matrix[top][i]);
                }
                top++;
                ctr++;
            }
            else if(ctr == 1){
                for(int i=top; i<=bottom; i++){
                    vec.push_back(matrix[i][right]);
                }
                right--;
                ctr++;
            }
            else if(ctr == 2){
                for(int i=right; i>=left; i--){
                    vec.push_back(matrix[bottom][i]);
                }
                bottom--;
                ctr++;
            }
            else{
                for(int i=bottom; i>=top; i--){
                    vec.push_back(matrix[i][left]);
                }
                left++;
                ctr++;
            }
            ctr = ctr % 4;
        }
        return vec;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
