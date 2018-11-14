#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		string res = "";
		int m = a.size() - 1, n = b.size() - 1;
		int num = 0;
		bool carry = false;
		while ((m + 1) || (n + 1) || carry) {
			num = 0;
			if (carry) num++;
			if (m >= 0) {
				if (a[m] == '1')
					num++;
				m--;
			}
			if (n >= 0) {
				if (b[n] == '1')
					num++;
				n--;
			}
			switch (num) {
			case 0:
				res.insert(res.begin(), '0');
				carry = false;
				break;
			case 1:
				res.insert(res.begin(), '1');
				carry = false;
				break;
			case 2:
				res.insert(res.begin(), '0');
				carry = true;
				break;
			case 3:
				res.insert(res.begin(), '1');
				carry = true;
				break;
			}
		}
		return res;
	}
};