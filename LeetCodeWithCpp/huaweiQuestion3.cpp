// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"
#include<set>
#include<map>


// 改成key代替坐标的一维矩阵，一维map
class Solution {
public:
	struct onePlace {
		int i;
		int j;
		int num;
		onePlace(int i, int j, int num) :i(i), j(j), num(num) {}
		bool operator<(const onePlace &monster)const {
			return num < monster.num;
		}
	};
	int key(const int &i, const int &j) {
		return i * M + j;
	}
	void read() {
		cin >> M;
		land = vector<vector<int>>(M, vector<int>(M, 0));
		bool exchange = false;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++) {
				scanf_s("%d", &land[i][j]);
				if (land[i][j] != 0) {
					exchange = land[i][j] == 1;
					if (i != 0 && land[i - 1][j] != 0) {
						//up
						if (exchange || land[i - 1][j] == 1) {
							adj[key(i, j)].push_back(key(i - 1, j));
							adj[key(i - 1, j)].push_back(key(i, j));
						}
						else if (land[i][j] > land[i - 1][j])
							adj[key(i - 1, j)].push_back(key(i, j));
						else if (land[i][j] < land[i - 1][j])
							adj[key(i, j)].push_back(key(i - 1, j));
					}
					if (j != 0 && land[i][j - 1] != 0) {
						//left
						if (exchange || land[i][j - 1] == 1) {
							adj[key(i, j)].push_back(key(i, j - 1));
							adj[key(i, j - 1)].push_back(key(i, j));
						}
						else if (land[i][j] > land[i][j - 1])
							adj[key(i, j - 1)].push_back(key(i, j));
						else if (land[i][j] < land[i][j - 1])
							adj[key(i, j)].push_back(key(i, j - 1));
					}
				}
			}
	}

	void process() {
		//auto iter1 = monsterPostion.cbegin();
		//auto iter2 = monsterPostion.cbegin();
		//iter2++;

	}

	void core(const int &currMonster, const int &currX, const int &currY) {

	}

	void dfs(const int &x,const int &y,const int &target) {
		int position = key(x, y);
		if (adj[position].size() == 0) return;
		for (int i = 0; i < adj[position].size(); i++) {
			if (marked[position])
				return;
			if (land[x][y] > target)
				return;
			else if (land[x][y] == target) {
				land[x][y] = 1;
			}
			marked[position] = true;
			dfs(adj[position][i], target);
		}
	}



private:
	int M;
	vector<vector<int>> land;
	//set<onePlace> monsterPostion;
	map<int, vector<int>> adj;
	map<int, bool> marked;
};


int main() {
	Solution slu;


	return 0;
}