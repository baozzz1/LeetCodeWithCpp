#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = -1, j = nums.size();
		int temp;
		while (i < j) {
			while (true) if(nums[++i] == val || i == j) break;
			while (true) if(nums[--j] != val || j == i) break;
			if (i >= j) break;
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
		return i;
	}
};