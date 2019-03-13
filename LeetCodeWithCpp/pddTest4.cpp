// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"

//  输入可能为非法的括号，返回合法的可能性
//((),()) 输出19
//拼多多实习生笔试第四题
class Solution {
public:
	Solution():result(0) {

	}
	void read() {
		s1 = "(()";
		s2 = "())";
	}

	void process() {
		int sum = 0;
		core(0, 0, sum);
		cout << result;
	}

	void core(const int &i, const int &j, int &sum) {
		int num;
		if (i < s1.size()) {
			num = s1[i] == '(' ? 1 : -1;
			sum += num;
			if (j == s2.size() && sum == 0)
				result++;
			if (sum >= 0)
				core(i + 1, j, sum);
			sum -= num;
		}
		if (j < s2.size()) {
			num = s2[j] == '(' ? 1 : -1;
			sum += num;
			if (i == s1.size() && sum == 0)
				result++;
			if (sum >= 0)
				core(i, j + 1, sum);
			sum -= num;
		}
	}

	/*void core_print(const int &i,const int &j,int &sum,string &str) {
		int num;
		string ori = str;
		if (i < s1.size()) {
			num = s1[i] == '(' ? 1 : -1;
			sum += num;
			ori += "s1[";
			ori += i + '0';
			ori += "] ";
			if (j == s2.size()  && sum == 0) {
				result++;
				cout << ori << endl;
			}
			if (sum >= 0)
				core(i + 1, j, sum, ori);
			sum -= num;
		}
		ori = str;
		if (j < s2.size()) {
			num = s2[j] == '(' ? 1 : -1;
			sum += num;
			ori += "s2[";
			ori += j + '0';
			ori += "] ";
			if (i == s1.size()  && sum == 0) {
				result++;
				cout << ori << endl;
			}
			if (sum >= 0)
				core(i, j + 1, sum, ori);
			sum -= num;
		}
	}*/

	string s1, s2;
	int result;
};


//int main() {
//	Solution slu;
//	slu.read();
//	slu.process();
//
//	return 0;
//}