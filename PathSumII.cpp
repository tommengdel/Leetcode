#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
    vector<vector<int> > paths;
    vector<int> path;
    bool isLeaf(TreeNode *root) {
        return root->left == 0 && root->right == 0;
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	// 不添加这两句，Leetcode通不过，但是在自己机器上却能够通过，怪哉
        paths.clear();
	path.clear();

        if(root != 0) ComputePaths(root, sum);
        return paths;
    }
    void ComputePaths(TreeNode *root, int sum) {
        path.push_back(root->val);
        if(isLeaf(root) && (root->val == sum)) paths.push_back(path);
        else {
            if(root->left != 0) ComputePaths(root->left, sum - root->val);
            if(root->right != 0) ComputePaths(root->right, sum - root->val);
        }        
        path.pop_back();
    }
};

