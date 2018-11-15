// Medium
#include<vector>
using namespace std;

// Quick3way
// Runtime: 4 ms, faster than 33.56% of C++ online submissions for Sort Colors.
// 可改进的点：此题已知三项的值分别为0,1,2，不需要用cmp差值判断了，而是直接判断是0,1,2中的一项即可。
class Solution {
public:
	void sortColors(vector<int>& nums) {
		sort(nums, 0, nums.size() - 1);
	}

	void sort(vector<int>& nums, int left, int right) {
		if (left >= right) return;
		int lt = left, i = left + 1, gt = right;
		int v = nums[left];
		int cmp;
		while (i <= gt) {
			cmp = nums[i] - v;
			if (cmp < 0) swap(nums[lt++], nums[i++]);
			else if (cmp > 0) swap(nums[i], nums[gt--]);
			else i++;
		}
		sort(nums, left, lt - 1);
		sort(nums, gt + 1, right);
	}

};