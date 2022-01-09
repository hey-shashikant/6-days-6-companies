// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Trie;

// Size of each TrieNode: O(N)
class TrieNode {
    unordered_map<char, TrieNode*> children;
    int count;
    // To store which all contacts end here
    vector<int> indices;
    
    friend Trie;

  public:
    TrieNode(int _count) {
        count = _count;
    }
};

class Trie {
    TrieNode* root;
    
    void insertAllPrefixesUtil(string s, TrieNode* node, int idx) {
        if(s.empty()) return;
        
        TrieNode* child = node->children[s[0]];
        if(child == NULL) {
            child = new TrieNode(1);
            node->children[s[0]] = child;
        }
        child->count++;
        child->indices.push_back(idx);
        insertAllPrefixesUtil(s.substr(1), child, idx);
    }
    
    void getDirectoryUtil(string s, vector<vector<string>> &res, TrieNode* node, vector<string> &p) {
        if(s.empty()) return;
        TrieNode* child = node->children[s[0]];
        if(child == NULL) return;
        int n = child->indices.size();
        vector<string> curr;
        for(int i = 0; i < n; i++) {
            curr.push_back(p[child->indices[i]]);
        }
        res.push_back(curr);
        getDirectoryUtil(s.substr(1), res, child, p);
    }
    
  public:
    Trie() {
        root = new TrieNode(0);
    }
    
    void insertAllPrefixes(string s, int idx) {
        insertAllPrefixesUtil(s, root, idx);
    }
    
    void getDirectory(string s, vector<vector<string>> &res, vector<string> &p) {
        getDirectoryUtil(s, res, root, p);
    }
};

class Solution {
  public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // SC: O(N * K)
        vector<vector<string>> res;
        vector<string> p = unqContacts(contact, n);
        n = p.size();
        Trie t;
        // TC: O(K * N), SC: O(N^2 * K)
        for(int i = 0; i < n; i++) {
            t.insertAllPrefixes(p[i], i);
        }
        // TC: O(S * K * N)
        t.getDirectory(s, res, p);
        // Push 0s for the rest
        while(res.size() < s.size()) res.push_back({"0"});
        
        return res;
    }
    
    // TC: O(K * NlogN), SC: O(N * K)
    vector<string> unqContacts(string a[], int n) {
        set<string> s(a, a + n);
        return vector<string>(s.begin(), s.end());
    }
};

// class Solution{
// public:
//     vector<vector<string>> displayContacts(int n, string contact[], string s)
//     {
//         // code here
//     }
// };

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
