#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		const unordered_set<char> symbols = { '!','?','\'',';','.',',' };
		string temp;
		unordered_set<string> banned_set(banned.begin(), banned.end());
		unordered_map<string, int> frequence;
		for (auto c : paragraph) {
			if (c == ' '|| symbols.find(c) != symbols.end()) {
				if (temp.size() == 0) continue;
				if (banned_set.find(temp) == banned_set.end())
					frequence[temp]++;
				temp.clear();
			}
			else {
				if (c < 'a') c += 32;
				temp.push_back(c);
			}
		}
		if (temp.size() != 0 && banned_set.find(temp) == banned_set.end())
			frequence[temp]++;
		string res;
		int maxFrequence = -1;
		for (auto iter = frequence.cbegin(); iter != frequence.cend(); ++iter) {
			if (iter->second > maxFrequence) {
				maxFrequence = iter->second;
				res = iter->first;
			}
		}
		return res;
	}
};

//int main() {
//	Solution slu;
//	string s1 = "a, a, a, a,b,b,b,c, c";
//	vector<string> banned = { "a" };
//	cout << slu.mostCommonWord(s1, banned);
//
//	return 0;
//}