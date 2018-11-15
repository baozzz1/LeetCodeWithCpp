#include"TreeNode.h"

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (root->left) {
			if (root->right)
				return min(minDepth(root->left), minDepth(root->right)) + 1;
			else
				return minDepth(root->left) + 1;
		}
		else {
			if (root->right)
				return minDepth(root->right) + 1;
			else
				return 1;
		}
	}
};