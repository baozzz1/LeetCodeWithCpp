#include"Interval.h"

// 一次通过！但不好看
// Runtime: 8 ms, faster than 99.22% of C++ online submissions for Insert Interval.
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		Interval curr = newInterval;
		vector<Interval> res;
		bool notInsert = true;
		int i = 0;
		for (; i < intervals.size() && notInsert; i++) {
			if (curr.start > intervals[i].end)
				res.push_back(intervals[i]);
			else if (curr.start >= intervals[i].start) {
				if (curr.end <= intervals[i].end) {
					res.push_back(intervals[i]);
					notInsert = false;
				}
				else
					curr.start = intervals[i].start;
			}
			else {
				if (curr.end <= intervals[i].end) {
					if (curr.end < intervals[i].start) {
						res.push_back(curr);
						res.push_back(intervals[i]);
					}
					else {
						curr.end = intervals[i].end;
						res.push_back(curr);
					}
					notInsert = false;
				}
			}
		}
		if (notInsert)
			res.push_back(curr);
		for (; i < intervals.size(); i++)
			res.push_back(intervals[i]);
		return res;
	}
};