#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		string res = "1";
		n--;
		while (n--)
			res = oneMore(res);
		return res;
	}

	string oneMore(string &n) {
		string res = "";
		char temp = n[0];
		int count = 1;
		for (int i = 1; i < n.size(); i++) {
			if (temp != n[i]) {
				res += to_string(count);
				res += temp;
				count = 0;
				temp = n[i];
			}
			count++;
		}
		res += to_string(count);
		res += temp;
		return res;
	}
};