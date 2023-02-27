class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return makeNodeRecurs(grid, 0, grid.size()-1, 0, grid.size()-1);
    }

    Node* makeNodeRecurs(vector<vector<int>>& grid, int i0, int i1, int j0, int j1) {        
        Node* curNode;
        if (i0 == i1) {
            curNode = new Node(grid[i0][j0], true);
        }
        else {
            int im = (i0+i1)/2, jm = (j0+j1)/2;
            Node* tL = makeNodeRecurs(grid, i0, im, j0, jm);
            Node* tR = makeNodeRecurs(grid, i0, im, jm+1, j1);
            Node* bL = makeNodeRecurs(grid, im+1, i1, j0, jm);            
            Node* bR = makeNodeRecurs(grid, im+1, i1, jm+1, j1);
            if (tL->isLeaf && tR->isLeaf && bL->isLeaf && bR->isLeaf && tL->val == tR->val && tR->val == bL->val && bL->val == bR->val) {
                curNode = new Node(tL->val, true);
                delete tL;
                delete tR;
                delete bL;
                delete bR;                
            }
            else {
                curNode = new Node(0, false, tL, tR, bL, bR);                
            }            
        }
        return curNode;
    }
};