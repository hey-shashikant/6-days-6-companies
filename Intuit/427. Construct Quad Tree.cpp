/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return getNode(grid, 0, 0, grid.size());
    }

    Node* getNode(vector<vector<int>>& grid, int x, int y, int n) {
        if (n == 1) {
            return new Node(grid[x][y], true);
        }

        if (isLeaf(grid, x, y, n)) {
            return new Node(grid[x][y], true);
        }

        int leafSize = n / 2;

        auto topLeft = getNode(grid, x, y, leafSize);
        auto topRight = getNode(grid, x, y + leafSize, leafSize);
        auto bottomLeft = getNode(grid, x + leafSize, y, leafSize);
        auto bottomRight = getNode(grid, x + leafSize, y + leafSize, leafSize);

        return new Node(grid[x][y], false, topLeft, topRight, bottomLeft, bottomRight);
    }

    bool isLeaf(vector<vector<int>>& grid, int x, int y, int n) {
        int val = grid[x][y];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[x + i][y + j] != val) {
                    return false;
                }
            }
        }

        return true;
    }
};
