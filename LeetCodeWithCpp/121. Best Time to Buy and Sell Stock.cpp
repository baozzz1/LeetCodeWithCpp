#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		int buyDay = 0, sellDay = prices.size() - 1;
		int maxProfit = 0;
		int profit = 0;
		int i = 1, j = prices.size() - 2;
		while (i <= j) {
			profit = prices[sellDay] - prices[buyDay];
			maxProfit = max(profit, maxProfit);
			while (j >= i) {
				if (prices[j] > prices[sellDay]) {
					sellDay = j;
					break;
				}
				if (prices[i] < prices[buyDay]) {
					buyDay = i;
					break;
				}
				j--;
				i++;
			}
		}
		profit = prices[sellDay] - prices[buyDay];
		maxProfit = max(profit, maxProfit);
		return maxProfit;
	}
};*/
