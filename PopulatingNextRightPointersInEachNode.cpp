/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeLinkNode *iterPar, *iterChild;
        root->next = 0;
        iterPar = root;
        iterChild = root->left;
        while(iterChild != 0) {
            while(iterPar != 0) {
                iterPar->left->next = iterPar->right;
                iterPar->right->next = iterPar->next == 0 ? 0 : iterPar->next->left;
                iterPar = iterPar->next;
            }
            
            iterPar = iterChild;
            iterChild = iterPar->left;           
        }
    }
};
//Accepted
