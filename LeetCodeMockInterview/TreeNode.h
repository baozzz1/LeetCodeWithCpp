#pragma once
#ifndef TREENODE_H
#define TREENODE_H

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

#endif // !TREENODE_H
