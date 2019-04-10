// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"

// Runtime: 4 ms, faster than 33.56% of C++ online submissions for Sort Colors.
// 可改进的点：
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size()*board[0].size() < word.size()) return false;
		vector<vector<bool>> isUsed(board.size(), vector<bool>(board[0].size()));
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == word[0]) {
					isUsed[i][j] = true;
					if (dfs(isUsed, i, j, 0, word, board))
						return true;
					isUsed[i][j] = false;
				}
			}
		}
		return false;
	}

	bool dfs(vector<vector<bool>> &isUsed, const int &i, const int &j, const int &index, const string &word, const vector<vector<char>>& board) {
		if (board[i][j] == word[index]) {
			if (index == word.size() - 1)
				return true;
		}
		else 
			return false;

		//bool res = false;
		int tempMapIndex = i - 1;
		if (tempMapIndex >= 0 && !isUsed[tempMapIndex][j]) {
			isUsed[tempMapIndex][j] = true;
			if (dfs(isUsed, tempMapIndex, j, index + 1, word, board))
				return true;
			isUsed[tempMapIndex][j] = false;
		}
		tempMapIndex = i + 1;
		if (tempMapIndex < board.size() && !isUsed[tempMapIndex][j]) {
			isUsed[tempMapIndex][j] = true;
			if (dfs(isUsed, tempMapIndex, j, index + 1, word, board))
				return true;
			isUsed[tempMapIndex][j] = false;
		}
		tempMapIndex = j - 1;
		if (tempMapIndex >= 0 && !isUsed[i][tempMapIndex]) {
			isUsed[i][tempMapIndex] = true;
			if (dfs(isUsed, i, tempMapIndex, index + 1, word, board))
				return true;
			isUsed[i][tempMapIndex] = false;
		}
		tempMapIndex = j + 1;
		if (tempMapIndex < board[0].size() && !isUsed[i][tempMapIndex]) {
			isUsed[i][tempMapIndex] = true;
			if (dfs(isUsed, i, tempMapIndex, index + 1, word, board))
				return true;
			isUsed[i][tempMapIndex] = false;
		}
		return false;
	}
};


int main() {
	vector<vector<char>>board = { {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'} ,{'A', 'D', 'E', 'E'}  };
	string word = "ABCCED";
	Solution slu;
	slu.exist(board,word);

	return 0;
}