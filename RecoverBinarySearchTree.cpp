#include<iostream>
using namespace std;
struct TreeNode {
       int val;
       TreeNode*  left;
       TreeNode*  right;
       TreeNode(int x) : val(x), left(0), right(0) {}
 };
//This One Accepted
class Solution {
public:

	void recoverTree(TreeNode *root)  {
		TreeNode *pre = 0, *curr = root, *first = 0, *second = 0;
		bool findFirstOne = false, findSecondOne = false;

		while(curr != 0 /*&& !findSecondOne */) {
			if(curr->left != 0) {
				//set up the thread or delete the thread
				TreeNode *p = curr->left;
				while(p->right != 0 && p->right != curr) p = p->right;
				if(p->right == 0) {
					p->right = curr;
					curr = curr->left;
				}
				else {
					p->right = 0;

					if(!findFirstOne) {
						if(pre != 0 && pre->val > curr->val)  {
							first = pre;
							findFirstOne = true;
						}
					}
					else {
						//we must find the second one
						if(!findSecondOne && curr->val > first->val) {
							second = pre;
							findSecondOne = true;
						}
					}

					pre = curr;
//					cout<<curr->val<<endl;
					curr = curr->right;
				}
			}
			else {
				if(!findFirstOne) {
					if(pre != 0 && pre->val > curr->val) {
						first = pre;
						findFirstOne = true;
					}
				}
				else {
					//we must find the second one
					if(!findSecondOne && curr->val > first->val) {
						second = pre;
						findSecondOne = true;
					}
				}
				pre = curr;
//				cout<<curr->val<<endl;
				curr = curr->right;
			}
		}

		if(!findSecondOne) second = pre;
		if(first == 0 || second == 0) return;
		int temp = first->val;
		first->val = second->val;
		second->val = temp;
		return;

	}
	
};

//
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool findFirstOne = false, findSecondOne = false;
        TreeNode *first, *second;
        
        TreeNode *pre = 0, *curr = root;
        while(curr != 0 && !findSecondOne) {
            if(curr->left != 0) {
                TreeNode *precedence = curr->left;
                while(precedence->right != 0 && precedence->right != curr) precedence = precedence->right;
                if(precedence->right == 0) {
                    precedence->right = curr;
                //    pre = curr;
                    curr = curr->left;
                }
                else {
                    precedence->right = 0;
                    if(!findFirstOne) {
                        if(pre != 0 && pre->val > curr->val) {
                            findFirstOne = true;
                            first = pre;
                        }
                    }
                    else {
                        //start finding second one
                        if(pre->val > curr->val) {
                            findSecondOne = true;
                            second = curr;
                        }
                    }
                    pre = curr;
                    curr = curr->right;
                }
            }
            else {
                 if(!findFirstOne) {
                        if(pre != 0 && pre->val > curr->val) {
                            findFirstOne = true;
                            first = pre;
                        }
                    }
                    else {
                        //start finding second one
                        if(pre->val > curr->val) {
                            findSecondOne = true;
                            second = curr;
                        }
                    }
                    pre = curr;
                    curr = curr->right;
            }
            
        }
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
     
    }
};
//Run time error: {0, 1}
//没有考虑极端情况，所以出错了。 这个方式是错误的。 
//
class Solution3 {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool findFirstOne = false, findSecondOne = false;
        TreeNode *first = 0, *second = 0;
        
        TreeNode *pre = 0, *curr = root;
        while(curr != 0 && !findSecondOne) {
            if(curr->left != 0) {
                TreeNode *precedence = curr->left;
                while(precedence->right != 0 && precedence->right != curr) precedence = precedence->right;
                if(precedence->right == 0) {
                    precedence->right = curr;
                //    pre = curr;
                    curr = curr->left;
                }
                else {
                    precedence->right = 0;
                    if(!findFirstOne) {
                        if(pre != 0 && pre->val > curr->val) {
                            findFirstOne = true;
                            first = pre;
                        }
                    }
                    
                        //start finding second one
                    if(findFirstOne && pre->val > curr->val) {
                            findSecondOne = true;
                            second = curr;
                    }
                    
                    pre = curr;
                    curr = curr->right;
                }
            }
            else {
                 if(!findFirstOne) {
                        if(pre != 0 && pre->val > curr->val) {
                            findFirstOne = true;
                            first = pre;
                        }
                    }
                    
                        //start finding second one
                    if(findFirstOne && pre->val > curr->val) {
                            findSecondOne = true;
                            second = curr;
                        }
                    
                    pre = curr;
                    curr = curr->right;
            }
            
        }
        if(first != 0 && second != 0) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        }
     
    }
};
//对于{0, 1}虽然是正确解，但是对于123654却会输出错误解
int main() {
	TreeNode root(68), L(41), LL(-85), LLL(-73), LLR(-49), LLLL(-98), LLLLL(-124);
	root.left = &L;
	L.left = &LL;
	LL.left = &LLL;
	LL.right = &LLR;
	LLL.left = &LLLL;
	LLLL.left = &LLLLL;
	Solution().recoverTree(&root);

	cout<<endl<<endl;
	Solution().recoverTree(&root);
}
//Solution2 Solution3 is incorrect!
