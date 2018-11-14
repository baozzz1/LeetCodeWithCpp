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

// Hard Question
class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode *curr = root;
		TreeNode *target = root;
		onePath(curr, target);

	}

	void onePath(TreeNode* curr, TreeNode* target) {
		if (!curr) return;
		target = new TreeNode(curr->val);
		target = target->left;
		onePath(curr->left, target);
		onePath(curr->right, target);
	}
};
int main() {
	Solution s;
	s.flatten()
}