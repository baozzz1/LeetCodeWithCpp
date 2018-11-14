#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// Hint: this is a fibonacci question.
class Solution {
public:
	int climbStairs(int n) {
		int sum = 0;
		int oneStep = 1;
		int twoStep = 0;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			ret = oneStep + twoStep;
			twoStep = oneStep;
			oneStep = ret;
		}
		return ret;
	}
};