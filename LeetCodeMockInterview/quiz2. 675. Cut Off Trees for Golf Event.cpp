// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"

class Solution {
public:
	struct position {
		int i, j;
		position() {}
		position(int i, int j) :i(i), j(j) {}
		bool operator==(const position &pos)const {
			if (i == pos.i && j == pos.j)
				return true;
			else return false;
		}
	};

	struct tree : position {
		int height;
		tree() {}
		tree(int i, int j, int h) :position(i, j), height(h) {}
		bool operator<(const tree &t)const {
			return height > t.height;
		}
	};

	int cutOffTree(vector<vector<int>>& forest) {
		if (forest.empty()) return 0;
		if (forest[0].empty()) return 0;
		rows = forest.size();
		cols = forest[0].size();
		priority_queue<tree/*,vector<tree>,less<tree>*/> trees;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				if (forest[i][j] > 1)
					trees.push(tree(i, j, forest[i][j]));
		int totalSteps = 0;
		tree curr;
		int step;
		position start_pos(0, 0);
		while (!trees.empty()) {
			curr = trees.top();
			trees.pop();
			step = minStep(start_pos, curr, forest);
			if (step < 0) return -1;
			totalSteps += step;
			start_pos = curr;
		}
		return totalSteps;
	}

	int minStep(const position &start_pos, const position &target_pos, const vector<vector<int>>& forest) {
		if (start_pos == target_pos) return 0;
		int step = 0;
		vector<vector<bool>> isMarked = vector<vector<bool>>(rows, vector<bool>(cols, false));
		queue<position> q;
		q.push(start_pos);
		isMarked[start_pos.i][start_pos.j] = true;

		int oneLevelSize;
		position curr;
		int next_i, next_j;
		while (!q.empty()) {
			oneLevelSize = q.size();
			for (int i = 0; i < oneLevelSize; i++) {
				curr = q.front();
				q.pop();
				if (curr == target_pos) return step;

				next_j = curr.j;
				//ÉÏ±ß
				next_i = curr.i - 1;
				if (next_i >= 0 && forest[next_i][next_j] != 0 && !isMarked[next_i][next_j]) {
					q.push(position(next_i, next_j));
					isMarked[next_i][next_j] = true;
				}
				//ÏÂ±ß
				next_i = curr.i + 1;
				if (next_i < rows && forest[next_i][next_j] != 0 && !isMarked[next_i][next_j]) {
					q.push(position(next_i, next_j));
					isMarked[next_i][next_j] = true;
				}

				next_i = curr.i;
				//×ó±ß
				next_j = curr.j - 1;
				if (next_j >= 0 && forest[next_i][next_j] != 0 && !isMarked[next_i][next_j]) {
					q.push(position(next_i, next_j));
					isMarked[next_i][next_j] = true;
				}
				//ÓÒ±ß
				next_j = curr.j + 1;
				if (next_j < cols && forest[next_i][next_j] != 0 && !isMarked[next_i][next_j]) {
					q.push(position(next_i, next_j));
					isMarked[next_i][next_j] = true;
				}
			}
			step++;
		}
		return -1;
	}

private:
	int rows, cols;
};

//int main() {
//	Solution slu;
//	vector<vector<int>> input = { {1,2,3},
//	{0,0,4},
//	{7,6,5} };
//	cout<< slu.cutOffTree(input);
//	return 0;
//}