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
	    vector<int> preorderTraversal(TreeNode *root) {
	            stack<TreeNode* > st;
		            vector<int> ret(0);
			            
				            //Preprocess
					            TreeNode *cur = root;
						            while(cur != 0) {
							                ret.push_back(cur->val);
									            if(cur->right != 0) st.push(cur->right);
										                cur = cur->left;
												        }
													        
														        while(!st.empty()) {
															            cur = st.top();
																                st.pop();
																		            while(cur != 0) {
																			                    ret.push_back(cur->val);
																					                    if(cur->right != 0) st.push(cur->right);
																							                    cur = cur->left;
																									                }
																											        }
																												        return ret;
																													    }
																													    };
