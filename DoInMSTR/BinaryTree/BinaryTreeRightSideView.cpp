/**
 * Definition for binary tree
  * struct TreeNode {
   *     int val;
    *     TreeNode *left;
     *     TreeNode *right;
      *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
       * };
        */
	class Solution {
	    
	    public:
	        vector<int> rightSideView(TreeNode *root) {
		        vector<int> result(0);   
			        fillRightSide(root, result, 0);
				        return result;
					    }
					        
						    void fillRightSide(TreeNode *root, vector<int> &vec, int height) {
						            if(root == 0) return;
							            if(height + 1 > vec.size()) vec.push_back(root->val);
								            fillRightSide(root->right, vec, height + 1);
									            fillRightSide(root->left, vec, height + 1);
										        } 
											};
