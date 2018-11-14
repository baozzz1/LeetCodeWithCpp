#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		return isSameSimpleTree(p, q);
	}

	bool isSameSimpleTree(TreeNode* p, TreeNode* q) {
		if (!p && !q)
			return true;
		if ((p && !q) || (!p && q))
			return false;
		if (p->val != q->val)
			return false;
		if (isSameSimpleTreeOneSide(p->left, q->left) && isSameSimpleTreeOneSide(p->right, q->right))
			return true;
		else
			return false;
	}

	bool isSameSimpleTreeOneSide(TreeNode* pOneSide, TreeNode* qOneSide) {
		bool oneSide = false;
		if (!pOneSide && !qOneSide) {
			oneSide = true;
		}
		else if (pOneSide && qOneSide)
			oneSide = isSameSimpleTree(pOneSide, qOneSide);
		return oneSide;
	}
};