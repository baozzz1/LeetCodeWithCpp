// Easy, Medium or Hard
// Medium
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> curr;
		int currSum = 0;
		dfs(k, 1, currSum, n, res, curr);
		return res;
	}

	void dfs(const int &k, const int &firstIndex, int &currSum, const int &n, vector<vector<int>> &res, vector<int> &curr) {
		if (currSum == n) {
			if (k == 0)
				res.push_back(curr);
			return;
		}
		else if (currSum > n)
			return;
		for (int i = firstIndex; i < 10; i++) {
			currSum += i;
			curr.push_back(i);
			dfs(k - 1, i + 1, currSum, n, res, curr);
			currSum -= i;
			curr.pop_back();
		}
	}
};


//int main() {
//	Solution slu;
//	slu.combinationSum3(3, 9);
//
//	return 0;
//}