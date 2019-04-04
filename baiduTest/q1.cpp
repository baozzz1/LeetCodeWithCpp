#include<iostream>
#include<string>
#include<set>

using namespace std;


int main() {
	string input;
	cin >> input;
	int n = input.size();
	set<char> sets;
	for (int i = 0; i < n; i++)
		sets.insert(input[i]);
	int max_n = sets.size();
	if (n == 0) {
		cout << 0;
		return 0;
	}
	string temp;
	int cycleLength = 0;
	for (int i = 0; i < max_n; i++) {
		temp += input[i];
		cycleLength++;
		int j;
		for (j = cycleLength; j < n; j += cycleLength) {
			if (temp != input.substr(j, cycleLength))
				break;
		}
		if (j == n) {
			cout << cycleLength;
			return 0;
		}
	}
	cout << n;
	return 0;
}