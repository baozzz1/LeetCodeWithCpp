#include<iostream>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;

class gameEvent {
public:
	// 找人、寻物、捕捉、战斗
	vector<double> init;
	vector<vector<double>> matrix;
	vector<vector<double>> reward;
	vector<int> input;
	//第一维和第二维度是4*4矩阵，第三维是S-D的5个元素
	vector<vector<vector<double>>> everyCase;
	void read() {
		//int num;
		init = vector<double>(4);
		matrix = vector<vector<double>>(4, vector<double>(4));
		reward = vector<vector<double>>(4, vector<double>(5));
		everyCase = vector<vector<vector<double>>>(4, vector<vector<double>>(4));
		for (int i = 0; i < 4; i++)
			cin >> init[i];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				cin >> matrix[i][j];
				everyCase[i][j] = vector<double>(5, matrix[i][j]);
			}
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++) {
				cin >> reward[i][j];
				for (int every_i = 0; every_i < 4; every_i++)
					everyCase[every_i][i][j] *= reward[i][j];
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

	void process2() {
		if (input.size() == 0) {
			cout << "1.0000";
			return;
		}
		vector<vector<double>> res = vector<vector<double>>(4, vector<double>(4, 1.0));
		vector<double> res_aux = vector<double >(4, 1.0);
		for (int i = input.size() - 1; i > 0; i--) {
			for (int t = 0; t < 4; t++) {
				for (int t_1 = 0; t_1 < 4; t_1++) {
					res[t][t_1] = everyCase[t][t_1][input[i]] * res_aux[t_1];
				}
			}
			//辅助矩阵
			for (int t = 0; t < 4; t++) {
				res_aux[t] = 0;
				for (int t_1 = 0; t_1 < 4; t_1++)
					res_aux[t] += res[t][t_1];
			}
		}
		double numRes = 0.0;
		for (int t = 0; t < 4; t++)
			for (int t_1 = 0; t_1 < 4; t_1++)
				numRes += res[t][t_1] * init[t] * reward[t][input[0]];
		double logRes = log10(numRes);
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
//	G.process2();
//	return 0;
//}