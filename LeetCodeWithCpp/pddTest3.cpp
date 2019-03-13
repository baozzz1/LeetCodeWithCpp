#include<iostream>
#include<stdio.h>
#include<math.h>
#include<set>
using namespace std;

struct bank {
	long postion;
	long money;
	bank(long p, long m) :postion(p), money(m) {}
	bool operator<(const bank &b2)const {
		return money > b2.money;
	}
};
//int main() {
//	int n, d;
//	cin >> n >> d;
//	long a, b;
//	set<bank> banks;
//	for (int i = 0; i < n; i++) {
//		scanf("%d %d", &a, &b);
//		banks.insert(bank(a, b));
//	}
//	long sum = 0;
//	long maxSum = 0;
//	for (auto iter = banks.begin(); iter != banks.end() && maxSum < 2 * (iter->money); ++iter) {
//		auto iter2 = iter;
//		iter2++;
//		while (iter2 != banks.end()) {
//			if (abs(iter->postion - iter2->postion) >= d) {
//				sum = iter->money + iter2->money;
//				if (sum > maxSum)
//					maxSum = sum;
//				break;
//			}
//			iter2++;
//		}
//	}
//	cout << maxSum;
//	return 0;
//}