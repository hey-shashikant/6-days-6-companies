// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


class Solution{
public:
    bool isValidrows(vector<vector<int>> &mat, int r){
        int freq[10] = {0};
        for(int i=0; i<mat.size(); i++){
            freq[mat[r][i]]++;
        }
        for(int i=1; i<10; i++){
            if(freq[i] > 1){
                return false;
            }
        }
        return true;
    }

    bool isValidcolumn(vector<vector<int>> &mat, int c){
        int freq[10] = {0};
        for(int i=0; i<mat.size(); i++){
            freq[mat[i][c]]++;
        }
        for(int i=1; i<10; i++){
            if(freq[i] > 1){
                return false;
            }
        }
        return true;
    }

    bool isValidsubgris(vector<vector<int>> &mat, int r,int c){
        int freq[10] = {0};
        for(int i=r; i<r+3; i++){
            for(int j=c; j<c+3; j++){
                freq[mat[i][j]]++;
            }
        }
        for(int i=1; i<10; i++){
            if(freq[i] > 1){
                return false;
            }
        }
        return true;
    }

    int isValid(vector<vector<int>> &mat){
        // code here
        // you need to check 3 conditions
        // 1. Valid subgrids
        // 2. for rows
        // 3. for columns
        bool flag = true;
        for(int i=0; i<mat.size(); i++){
            if(isValidrows(mat,i) == false or isValidcolumn(mat,i) == false){
                // return 0;
                flag = false;
                break;
            }
        }
        // for(int i=0; i<mat.size(); i++){
        //     if(isValidcolumn(mat,i) == false){
        //         return 0;
        //         break;
        //     }
        // }

        for(int i=0; i<mat.size(); i+=3){
            for(int j=0; j<mat.size(); j+=3){
                if(isValidsubgris(mat,i,j) == false){
                    // return 0;
                    flag = false;
                    break;
                }
            }
        }
        if(flag == true){
            return 1;
        }
        return 0;

    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
