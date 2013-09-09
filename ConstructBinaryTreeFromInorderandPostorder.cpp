#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 //* Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
    typedef vector<int>::iterator VIT;
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    
    TreeNode *buildTree(VIT in_s, VIT in_e, VIT pos_s, VIT pos_e) {
        int t = pos_e - pos_s;
        if(t == 0) return 0;
        else if(t == 1) {
            return new TreeNode(*pos_s);
        }
//        	inorder.push_back(1)i
        TreeNode *root = new TreeNode(*(pos_e - 1));
        VIT mid = find(in_s, in_e, *(pos_e - 1));
	
        int leftNum = mid - in_s;
        int rightNum = t - 1 - leftNum;
	cout<<leftNum + rightNum<<endl;
        root->left = buildTree(in_s, mid, pos_s, pos_s + leftNum);
        root->right = buildTree(mid + 1, in_e, pos_s + leftNum, pos_e - 1);
	//My Mistake: buildTree(mid, in_e, pos_s + leftNum, pos_e);
        return root;    
        
    }
};

int main() {
	vector<int> inorder, postorder;
	inorder.push_back(1);	inorder.push_back(3);inorder.push_back(2);
	postorder.push_back(3); postorder.push_back(2); postorder.push_back(1);
	Solution().buildTree(inorder, postorder);
}
