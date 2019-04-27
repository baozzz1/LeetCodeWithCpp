// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"
class Solution {
public:
	Solution() :pathsNum(0) {}
	int uniquePathsIII(vector<vector<int>>& grid) {
		m = grid.size();
		if (m == 0) return 0;
		n = grid[0].size();
		if (n == 0) return 0;

		count = 0;
		pathsNum = 0;
		hasWalked = vector<vector<bool>>(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				switch (grid[i][j]) {
				case 0:
					count++;
					break;
				case -1:
					hasWalked[i][j] = true;
					break;
				case 1:
					curr_i = i;
					curr_j = j;
					count++;
					break;
				case 2:
					target_i = i;
					target_j = j;
					count++;
					break;
				}
			}
		}
		dfs();
		return pathsNum;
	}

	void dfs() {
		if (curr_i < 0 || curr_j < 0 || curr_i >= m || curr_j >= n)
			return;
		if (!hasWalked[curr_i][curr_j]) {
			hasWalked[curr_i][curr_j] = true;
			count--;
			if (curr_i == target_i && curr_j == target_j) {
				if (count == 0)
					pathsNum++;
				hasWalked[curr_i][curr_j] = false;
				count++;
				return;
			}

			//left
			curr_j--;
			dfs();
			curr_j++;

			//right
			curr_j++;
			dfs();
			curr_j--;

			//up
			curr_i--;
			dfs();
			curr_i++;

			//down
			curr_i++;
			dfs();
			curr_i--;

			hasWalked[curr_i][curr_j] = false;
			count++;
		}

	}

private:
	int pathsNum;
	int curr_i, curr_j;
	int target_i, target_j;
	int m, n;
	int count;
	vector<vector<bool>> hasWalked;
};

//int main() {
//	vector<vector<int>> grids = { {1,0,0,0},{0,0,0,0},{0,0,2,-1} };
//	Solution slu;
//	int res = slu.uniquePathsIII(grids);
//	return 0;
//}