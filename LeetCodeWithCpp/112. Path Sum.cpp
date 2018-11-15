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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
			return false;
		if (!root->left && !root->right && sum == root->val)
			return true;
		bool left = false, right = false;
		left = hasPathSum(root->left, sum - root->val);
		right = hasPathSum(root->right, sum - root->val);
		return left || right;
	}
};