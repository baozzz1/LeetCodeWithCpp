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
	int maxDepth(TreeNode* root) {
		return depth(root);
	}
	int depth(TreeNode* node) {
		if (!node)   return 0;
		return max(depth(node->left), depth(node->right)) + 1;
	}
};