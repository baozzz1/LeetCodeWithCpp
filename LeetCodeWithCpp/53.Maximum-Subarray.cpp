#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> sum(nums.size(), INT_MIN);
		sum[0] = nums[0];
		for (int i = 0; i < nums.size(); i++)
			sum[i] = max(nums[i], nums[i] + sum[i - 1]);
		return *max_element(sum.begin(), sum.end());
	}
};