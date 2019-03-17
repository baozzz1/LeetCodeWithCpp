// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"
#include<set>
#include<map>

struct monster {
	monster(int m, int i) :monsterSize(m), index(i) {}
	int monsterSize;
	int index;
	bool operator<(const monster &m)const {
		return monsterSize < m.monsterSize;
	}
};
// 改成key代替坐标的一维矩阵，一维map
class Solution {
public:
	Solution() {
		values = vector<int>(2500, 0);
		isMarked = vector<bool>(2500, false);
	}

	void read() {
		int num; int i = 0;
		while (cin >> num) {
			if (num > 1)
				monsters.push_back(monster(num, i));
			values[i++] = num;
		}
		sort(monsters.begin(), monsters.end());
		M = sqrt(i);

		adj = vector<vector<int>>(i);
		for (int i = 0; i < M ; i++)
			for (int j = 0; j < M ; j++)
				makeLink(i, j);
	}

	void process() {
		int currIndex = 0;
		totalSteps = 0;
		for (int i = 0; i < monsters.size(); i++) {
			flag = false;
			dfs(currIndex, i, 0);
			if (flag)
				currIndex = monsters[i].index;
			else
				break;
		}
		if (flag)
			cout << totalSteps;
		else
			cout << -1;
	}

private:
	int M;
	vector<int> values;	//下标等于i*M+j
	vector<bool> isMarked;
	vector< monster> monsters;
	vector<vector<int>> adj;
	int totalSteps;
	bool flag;

	void makeLink(const int &i, const int &j) {
		int index = i * M + j;
		if (values[index] == 0) return;
		//向右
		if (j != M - 1) {
			if (values[index + 1] != 0) {
				if (values[index] < values[index + 1])
					adj[index].push_back(index + 1);
				else if (values[index] > values[index + 1])
					adj[index + 1].push_back(index);
				else {
					adj[index + 1].push_back(index);
					adj[index].push_back(index + 1);
				}
			}
		}
		//向下
		if (i != M - 1) {
			if (values[index + M] != 0) {
				if (values[index] < values[index + M])
					adj[index].push_back(index + M);
				else if (values[index] > values[index + M])
					adj[index + M].push_back(index);
				else {
					adj[index + M].push_back(index);
					adj[index].push_back(index + M);
				}
			}
		}
	}

	void dfs(const int &node, const int &monIndex, const int &steps) {
		if (adj[node].size() == 0) return;
		int nextIndex;
		for (int i = 0; i < adj[node].size(); i++) {
			nextIndex = adj[node][i];
			//cout <<node << " -> " << nextIndex << endl;
			if (isMarked[nextIndex]) continue;
			if (values[nextIndex] == 0) continue;
			else if (values[nextIndex] == monsters[monIndex].monsterSize) {
				//找到目的地
				totalSteps += steps + 1;
				flag = true;
				//把怪兽变回陆地，并建立连接
				values[nextIndex] = 1;
				int indexI = nextIndex / M;
				int indexJ = nextIndex % M;
				if (indexJ != 0 && values[nextIndex - 1] != 0)
					adj[nextIndex].push_back(nextIndex - 1);
				if (indexJ != M - 1 && values[nextIndex + 1] != 0)
					adj[nextIndex].push_back(nextIndex + 1);
				if (indexI != 0 && values[nextIndex - M] != 0)
					adj[nextIndex].push_back(nextIndex - M);
				if (indexI != M - 1 && values[nextIndex + M] != 0)
					adj[nextIndex].push_back(nextIndex + M);
				return;
			}
			else if (values[nextIndex] == 1) {
				isMarked[node] = true;
				dfs(nextIndex, monIndex, steps + 1);
				isMarked[node] = false;
			}
		}
	}

	int dfsPath(const int &startIndex, const int &targetIndex) {

		return 0;
	}
};


//int main() {
//	Solution slu;
//	slu.read();
//	slu.process();
//
//	return 0;
//}