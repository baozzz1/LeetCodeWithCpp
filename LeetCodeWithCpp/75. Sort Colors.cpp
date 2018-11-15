// Medium
#include<vector>
using namespace std;

// Quick3way
// Runtime: 4 ms, faster than 33.56% of C++ online submissions for Sort Colors.
// �ɸĽ��ĵ㣺������֪�����ֵ�ֱ�Ϊ0,1,2������Ҫ��cmp��ֵ�ж��ˣ�����ֱ���ж���0,1,2�е�һ��ɡ�
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