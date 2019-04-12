// Easy, Medium or Hard
// Medium
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"
#include<map>
#include<queue>

// Runtime: 4 ms, faster than 33.56% of C++ online submissions for Sort Colors.
// 可改进的点：
struct cmp
{
	bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
		return p1.second > p2.second;
};
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> mp;
		for (auto n : nums)
			mp[n]++;
		//auto cmp = [](pair<int, int> &p1, pair<int, int> &p2) {return p1.second > p2.second; };
		priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> pq;
		for (auto p_pair : mp) {
			if (pq.size() < k)
				pq.push(p_pair);
			else {
				if (p_pair.second > pq.top().second) {
					pq.pop();
					pq.push(p_pair);
				}
			}
		}
		vector<int> res;
		return res;

	}
};


int main() {
	Solution slu;
	vector<int> v({ 1,1,1,2,2 });
	int k = 2;
	slu.topKFrequent(v,k);

	return 0;
}