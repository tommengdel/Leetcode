/**
 * Definition for binary tree
  * struct TreeNode {
   *     int val;
    *     TreeNode *left;
     *     TreeNode *right;
      *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
       * };
        */
	class BSTIterator {
	    stack<TreeNode*> st;
	    public:
	        BSTIterator(TreeNode *root) {
		        while(root != 0) {
			            st.push(root);
				                root = root->left;
						        }
							    }

							        /** @return whether we have a next smallest number */
								    bool hasNext() {
								            return !st.empty();
									        }

										    /** @return the next smallest number */
										        int next() {
											        TreeNode *next = st.top();
												        st.pop();
													        TreeNode *cur = next->right;
														        while(cur != 0) {
															            st.push(cur);
																                cur = cur->left;
																		        }
																			        return next->val;
																				    }
																				    };

																				    /**
																				     * Your BSTIterator will be called like this:
																				      * BSTIterator i = BSTIterator(root);
																				       * while (i.hasNext()) cout << i.next();
																				        */
