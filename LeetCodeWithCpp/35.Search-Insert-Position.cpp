#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (!nums.size())
			return 0;
		return  binary(nums, 0, nums.size() - 1, target);
	}

	int binary(vector<int> &nums, int left, int right, const int &target) {
		int mid = (left + right) / 2;
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
		else if (nums[mid] == target)
			return mid;
		if (left >= right) {
			if (nums[right] >= target)
				return right;
			else
				return right + 1;
		}
		return binary(nums, left, right, target);
	}
};