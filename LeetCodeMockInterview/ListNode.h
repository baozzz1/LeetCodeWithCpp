#pragma once
#ifndef LISTNODE_H
#define LISTNODE_H

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#endif // !LISTNODE_H
