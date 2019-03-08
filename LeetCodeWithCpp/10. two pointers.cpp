// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"

// Runtime: 4 ms, faster than 33.56% of C++ online submissions for Sort Colors.
// 可改进的点：
class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1;
		int maxArea = 0;
		int currArea;
		bool leftMove;
		while (i < j) {
			leftMove = height[i] < height[j];
			currArea = (leftMove ? height[j] : height[i])*(j - i);
			if (currArea > maxArea)
				maxArea = currArea;
			if (leftMove)
				i++;
			else
				j--;
		}
		return maxArea;
	}
};