#include"TreeNode.h"

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