#include"TreeNode.h"

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)	return res;
		vector<TreeNode*> head = { root };
		insertAtBottom(head, res);
		res.push_back((vector<int>{root->val}));
		return res;
	}

	void insertAtBottom(vector<TreeNode*> nodes, vector<vector<int>> &res) {
		vector<TreeNode*> down;
		for (auto &node : nodes) {
			if (!node)	continue;
			down.push_back(node->left);
			down.push_back(node->right);
		}
		if (down.empty())
			return;
		insertAtBottom(down, res);
		vector<int> temp;
		for (int i = 0; i < down.size(); i++) {
			if (down[i])
				temp.push_back(down[i]->val);
		}
		if (temp.size())
			res.push_back(temp);
	}
};