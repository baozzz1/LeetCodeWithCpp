#include"TreeNode.h"

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> path;
		onePath(root, sum, path, res);
		return res;
	}

	void onePath(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &paths) {
		if (!root)  return;
		path.push_back(root->val);
		if (!root->left & !root->right && root->val == sum) {
			paths.push_back(path);
		}
		onePath(root->left, sum - root->val, path, paths);
		onePath(root->right, sum - root->val, path, paths);
		path.pop_back();
	}
};