#include"Interval.h"

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		sort(intervals.begin(), intervals.end(), [](Interval& item1, Interval& item2) {return (item1.start == item2.start) ? (item1.end < item2.end) : (item1.start < item2.start); });
		mergeOneTime(0, intervals, res);
		return res;
	}

	void mergeOneTime(int curr, vector<Interval>& intervals, vector<Interval>& res) {
		if (curr == intervals.size())
			return;
		int first = intervals[curr].start;
		int last = intervals[curr].end;
		curr++;
		for (; curr < intervals.size(); curr++) {
			if (intervals[curr].start > last || intervals[curr].end < first)
				break;
			last = max(intervals[curr].end, last);
			first = min(intervals[curr].start, first);
		}
		res.push_back(Interval(first, last));
		mergeOneTime(curr, intervals, res);
		return;
	}
};