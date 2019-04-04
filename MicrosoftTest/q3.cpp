#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>

using namespace std;
// Read only region start

int findPosition(int input1, int input2, vector<vector<int>> input3)
{
	// Read only region end
	// Write code and remove the below exception.
	//vector<int> vec(input1+1);
	map<int, int> mp;
	for (int i = 1; i <= input1; i++) {
		//vec[i]=i;
		mp[i] = i;
	}
	int firstPeople = 1;
	int res = 0;
	int E, X;
	int currIndex;
	for (int i = 0; i < input2; i++) {
		E = input3[i][0];
		X = input3[i][1];
		switch (E) {
		case 1:
			mp[firstPeople] = 0;
			for (map<int, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter) {
				iter->second--;
				if (iter->second == 1)
					firstPeople = iter->first;
			}
			break;
		case 2:
			currIndex = mp[X];
			mp[X] = 0;
			for (map<int, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter) {
				if (iter->second > currIndex)
					iter->second--;
			}
			break;
		case 3:
			res += mp[X];
			break;
		}
	}
	return res;
	
}
//int main() {
//	vector<vector<int>> res = { {1,0},{3,3},{2,2} };
//	findPosition(5, 3, res);
//}