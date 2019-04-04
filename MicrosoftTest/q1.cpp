#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>

using namespace std;

int core(const int &left, const int &right, const vector<int> &arr) {
	if (left > right)
		return 0;
	else if (left<0 || right>arr.size() - 1)
		return 0;
	else if (left == right)
		return 1;
	else if (arr[left] == arr[right])
		return core(left + 1, right - 1, arr);
	int res = 0;
	int coupleNum = 0;
	int singleNum = 0;
	int minIndex = left;
	int maxIndex = right;
	int maxLength = 0;
	map<int, vector<int> > mp;
	for (int i = left; i <= right; i++) {
		mp[arr[i]].push_back(i);
	}
	int length;
	for (map<int, vector<int> >::iterator iter = mp.begin(); iter != mp.end(); iter++) {
		//for(auto iter : mp){
		int n = (iter->second).size();
		if (n > 1) {
			length = iter->second[n - 1] - iter->second[0] + 1;
			if (length > maxLength) {
				maxLength = length;
				minIndex = iter->second[0];
				maxIndex = iter->second[n - 1];
			}
		}
	}
	if (minIndex == left && maxIndex == right)
		return right - left + 1;
	else if (minIndex == left) {
		return core(left + 1, maxIndex - 1, arr) + core(maxIndex + 1, right, arr);
	}
	else if (maxIndex == right)
		return core(left, minIndex - 1, arr) + core(minIndex + 1, right, arr);
	else
		return core(left, minIndex - 1, arr) + core(minIndex + 1, maxIndex - 1, arr) + core(maxIndex + 1, right, arr);
}

// Read only region start

int points(int input1, int input2[])
{
	// Read only region end
	// Write code and remove the below exception.
	vector<int> vec(input1);
	for (int i = 0; i < input1; i++)
		vec[i] = input2[i];
	int num = core(0, input1 - 1, vec);
	return num;
}
//
//int main() {
//	int res[2] = { 1,2 };
//	points(2,res);
//}