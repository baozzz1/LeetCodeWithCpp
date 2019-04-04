#include<stdio.h>
#include<string.h>

int dfs(const int &currIndex, const int &iniIndex, const int &times, const int &maxTimes, const int &size) {
	int res = 0;
	if (times == maxTimes) {
		if (currIndex == iniIndex)
			return 1;
		else return 0;
	}
	if (currIndex == iniIndex && times!=0)
		res += 1;
	int maxNum, minNum;
	for (int i = 1; i < currIndex; i++) {
		if (currIndex % i == 0)
			res += dfs(i, iniIndex, times + 1, maxTimes, size);
	}
	for (int i = currIndex + 1; i <= size; i++) {
		if (i % currIndex == 0)
			res += dfs(i, iniIndex, times + 1, maxTimes, size);
	}
	return res;
}
// Read only region start

int maxCircles(int input1, int input2, int input3)
{
	// Read only region end
	// Write code and remove the below exception.
	int times = 0;
	int num =  dfs(input2, input2, times, input3, input1);
	return num;
}
//
//int main() {
//	maxCircles(3, 2, 4);
//	return 0;
//}