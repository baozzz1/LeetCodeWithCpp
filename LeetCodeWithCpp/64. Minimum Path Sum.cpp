// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"

// Runtime: 4 ms, faster than 33.56% of C++ online submissions for Sort Colors.
// 可改进的点：
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		if (n == 0) return 0;
		vector<int> dp(n, 0);
		dp[0] = grid[0][0];
		for (int j = 1; j < n; j++)
			dp[j] = dp[j - 1] + grid[0][j];
		for (int i = 1; i < m; i++) {
			dp[0] += grid[i][0];
			for (int j = 1; j < n; j++) {
				dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
			}
		}
		return dp[n - 1];
	}
};


//int main() {
//	Solution slu;
//	vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
//	slu.minPathSum(grid);
//	return 0;
//}