/*************************************
Best Time to Buy and Sell Stock : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
**/

//@time complexity: O(n)
//@space complexity: O(1)
//@2A
int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1) {
		return 0;
	}
	int profit = INT_MIN;
	int minIdx = 0;
	for (int i = 1; i < prices.size(); i++) {
		int tmp = prices[i] - prices[minIdx];
		if (tmp > profit) {
			profit = tmp;
		}
		if (prices[i] < prices[minIdx]) {
			minIdx = i;
		}
	}

	if (profit < 0) {
		return 0;
	}

	return profit;
}