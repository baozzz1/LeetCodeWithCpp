#include<iostream>
#include<string>
#include<vector>

using namespace std;

int fun(int m, int n) {//m个苹果放在n个盘子中共有几种方法
	if (m == 0 || n == 1)
		return 1;
	if (n > m)
		return fun(m, m);
	else
		return fun(m, n - 1) + fun(m - n, n);
}

int main() {
	int M, N, K;
	cin >> M >> N >> K;
	vector<int> m(K + 1, 0);
	vector<int> n(K + 1, 0);
	for (int i = 1; i <= M; i++) {
		m[i] = fun(M - i, i);
	}
	for (int i = 1; i <= N; i++) {
		n[i] = fun(N - i, i);
	}
	int res = 0;
	for (int i = 1; i < K; i++) {
		for (int j = 1; j <= K - i; j++) {
			res += m[i] * n[j];
			res = res % 10000;
		}
	}
	cout << res;
	return 0;
}