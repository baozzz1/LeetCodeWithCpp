#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	// Easy way
	int mySqrt_1(int x) {
		return (int)sqrt(x);
	}

	int mySqrt(int x) {
		int lhs = 0, rhs = x;
		while (lhs != rhs) {
			long long middle = (rhs + lhs) / 2;
			if (middle *middle < x) lhs = middle + 1;
			else rhs = middle;
		}
		return lhs * lhs == x ? lhs : lhs - 1;
	}
};