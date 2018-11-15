#include"TreeNode.h"

class Solution {
public:
	int maxDepth(TreeNode* root) {
		return depth(root);
	}
	int depth(TreeNode* node) {
		if (!node)   return 0;
		return max(depth(node->left), depth(node->right)) + 1;
	}
};