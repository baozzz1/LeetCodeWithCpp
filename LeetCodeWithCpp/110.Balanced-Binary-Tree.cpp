#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;
		if (isBalanced(root->left) && isBalanced(root->right))
			if (abs(depth(root->left) - depth(root->right)) <= 1)
				return true;
		return false;
	}

	int depth(TreeNode* root) {
		if (!root)
			return 0;
		return max(depth(root->left), depth(root->right)) + 1;
	}
};