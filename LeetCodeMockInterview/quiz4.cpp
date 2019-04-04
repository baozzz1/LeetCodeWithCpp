// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"
#include<set>

class Solution {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
		set<double> ratios;
		worker w;
		for (int i = 0; i < quality.size(); i++) {
			w = worker(quality[i], wage[i]);
			workers.insert(w);
			ratios.insert(w.ratio);
		}
		int num;
		double sum;
		double temp;
		double minSum = MAX_DOUBLE;
		for (auto ratio : ratios) {
			num = 0;
			sum = 0.0;
			for (auto iter = workers.begin(); iter != workers.end() && num < K; ++iter) {
				temp = iter->quality * ratio;
				if (ratio < iter->ratio) continue;
				sum += temp;
				num++;
			}
			if (num != K) continue;
			if (sum < minSum) minSum = sum;
		}
		return minSum;
	}
private:
	const double MAX_DOUBLE = numeric_limits<unsigned long>::max();
	class worker {
	public:
		int quality;
		int wage;
		double ratio;
		worker() {}
		worker(const int &q, const int &w) :quality(q), wage(w) {
			ratio = double(w) / double(q);
		}
		bool operator<(const worker &w2)const {
			if (quality == w2.quality)
				return wage < w2.wage;
			else return quality < w2.quality;
		}
	};
	multiset<worker> workers;
	
};

int main() {
	Solution slu;
	vector<int> q = { 3, 1, 10, 10, 1 };
	vector<int> w = { 4, 8, 2, 2, 7 };
	int K = 3;
	cout << slu.mincostToHireWorkers(q, w, K);

}