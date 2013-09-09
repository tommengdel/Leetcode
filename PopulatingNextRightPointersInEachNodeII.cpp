/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Soluti

on {
    bool isLeaf(TreeLinkNode *root) {
        return root->left == 0 && root->right == 0;
    }
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == 0) return;
        TreeLinkNode *iterPar = root, *iterChild;   
        root->next = 0;
        iterChild = iterPar->left == 0 ? iterPar->right : iterPar->left;
        while(iterChild != 0) {
		while(iterPar != 0) {
	            if(iterPar->left != 0) {
        	        TreeLinkNode *next = 0;
	                if(iterPar->right != 0) next = iterPar->right;
        	        else {
                	    TreeLinkNode *p = iterPar->next;
	                    while(p != 0 && isLeaf(p)) p = p->next;
                    
        	            if(p != 0) next = p->left == 0 ? p->right: p->left;
                	    else next = 0;
                	}
                
               		iterPar->left->next = next;
            	     }
            	    if(iterPar->right != 0) {
	                TreeLinkNode *next = 0;
        	        TreeLinkNode *p = iterPar->next;
                	while(p != 0 && isLeaf(p)) p = p->next;
	                if(p != 0) next = p->left == 0 ? p->right : p->left;
        	        iterPar->right->next = next;
	            }
         	iterPar = iterPar->next;
	   	}
            while(iterChild != 0 && isLeaf(iterChild)) iterChild = iterChild->next;
            if(iterChild != 0) {
                iterPar = iterChild;
                iterChild = iterPar->left == 0 ? iterPar->right : iterPar->left;
            }
        }
    }
};


