//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//int n;
//
//int main() {
//	cin >> n;
//	vector<double> p(n, 0);
//	for (int i = 0; i < n; i++)
//		cin >> p[i];
//	double res = 0;
//	double k = 1;
//	for(int j=0;j<50;j++)
//		for (int i = 0; i < 2 * n; i+=2) {
//			res += k * p[i%n];
//			k *= (1.0 - p[i%n])*(1.0 - p[(i + 1) % n]);
//		}
//	printf("%.4f", res);
//	return 0;
//}