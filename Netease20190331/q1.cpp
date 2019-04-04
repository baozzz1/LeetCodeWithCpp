#include<iostream>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;
/*
0.4 0.3 0.2 0.1
0.5 0.2 0.2 0.1
0.1 0.4 0.1 0.4
0.3 0.1 0.3 0.3
0.2 0.4 0.2 0.2
0.05 0.10 0.20 0.30 0.35
0.08 0.15 0.25 0.35 0.17
0.15 0.25 0.30 0.20 0.10
0.20 0.40 0.20 0.15 0.05
D B B A
*/
//超时 
class gameEvent {
public:
	// 找人、寻物、捕捉、战斗
	vector<double> init;
	vector<vector<double>> matrix;
	vector<vector<double>> reward;
	vector<int> input;
	void read() {
		init = vector<double>(4);
		matrix = vector<vector<double>>(4, vector<double>(4));
		reward = vector<vector<double>>(4, vector<double>(5));
		for (int i = 0; i < 4; i++)
			cin >> init[i];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				cin >> matrix[i][j];
			}
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++) {
				cin >> reward[i][j];
			}
		char c;
		while (cin >> c)
			input.push_back(whichLevel(c));

	}

	void process() {
		if (input.size() == 0) {
			cout << "1.0000";
			return;
		}
		double res = 0;
		int iter = 0;
		for (int i = 0; i < 4; i++) {
			res += init[i] * reward[i][input[iter]] * nextSolution(i, iter + 1);
		}
		double logRes = log10(res);
		printf("%.4f", logRes);
	}

private:
	int whichLevel(const char &c) {
		switch (c) {
		case 'S':
			return 0;
			break;
		case 'A':
			return 1;
			break;
		case 'B':
			return 2;
			break;
		case 'C':
			return 3;
			break;
		case 'D':
			return 4;
			break;
		default:
			return 0;
			break;
		}
	}

	double nextSolution(const int &lastCase, const int &iter) {
		if (iter >= input.size()) return 1.0;
		double res = 0;
		for (int i = 0; i < 4; i++) {
			res += matrix[lastCase][i] * reward[i][input[iter]] * nextSolution(i, iter + 1);
		}
		return res;
	}
};
//
//int main() {
//	gameEvent G;
//	G.read();
//	G.process();
//	return 0;
//}