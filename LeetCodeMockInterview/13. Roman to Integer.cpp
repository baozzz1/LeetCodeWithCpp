#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int sum = 0;
		int index = 0;
		bool cBefore = false;
		bool xBefore = false;
		bool iBefore = false;
		for (; index < s.size(); index++) {
			switch (s[index]) {
			case 'M':
				sum += 1000;
				if (cBefore) {
					sum -= 200;
					cBefore = false;
				}
				break;
			case 'D':
				sum += 500;
				if (cBefore) {
					sum -= 200;
					cBefore = false;
				}
				break;
			case 'C':
				sum += 100;
				cBefore = true;
				if (xBefore) {
					sum -= 20;
					xBefore = false;
				}
				break;
			case 'L':
				sum += 50;
				if (xBefore) {
					sum -= 20;
					xBefore = false;
				}
				break;
			case 'X':
				sum += 10;
				xBefore = true;
				if (iBefore) {
					sum -= 2;
					iBefore = true;
				}
				break;
			case 'V':
				sum += 5;
				if (iBefore) {
					sum -= 2;
					iBefore = true;
				}
				break;
			case 'I':
				sum += 1;
				iBefore = true;
				break;
			}
		}
		return sum;
	}
};