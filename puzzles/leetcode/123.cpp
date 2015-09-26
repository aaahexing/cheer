/***********************************
Best Time to Buy and Sell Stock III : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
**/

//-----------------------------------------solution 1-----------------------------------------------------
//@time limit exceeded
//@time complexity: O(n^2)
//@space complexity: O(n^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        
        int size = prices.size();
        vector<vector<int>> profixs(size, vector<int>(size, 0));
        getProfixs(prices, profixs);
        
        int maxProfit = 0;
        for (int i = 1; i < size; i++) {
            int tmpProfit = profixs[0][i];
            for (int j = 1; j < i; j++) {
                int left = profixs[0][j];
                int right = profixs[j][i];
                if (left + right > tmpProfit) {
                    tmpProfit = left + right;
                }
            }
            
            if (tmpProfit > maxProfit) {
                maxProfit = tmpProfit;
            }
        }
        
        return maxProfit;
    }
    
    void getProfixs(vector<int> & prices, vector<vector<int>> & profixs) {
        for (int i = 0; i < prices.size(); i++) {
            int minIdx = i;
            for (int j = i; j < prices.size(); j++) {
                if (prices[j] - prices[minIdx] > profixs[i][j]) {
                    profixs[i][j] = prices[j] - prices[minIdx];
                }
                
                if (prices[j] < prices[minIdx]) {
                    minIdx = j;
                }
            }
        }
    }
};

//-----------------------------------------------solution 2-------------------------------------------
//@time complexity: O(n)
//@space complexity: O(n)
//@2A
//@desc: gets all maxProfix in [0, j); 0 <= j <= n
//@desc: gets all maxProfix in [j, n); 0 <= j <= n
//@desc: dynamic programming...then
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        
        vector<int> profixsToJ(prices.size(), 0);
        vector<int> profixsStartI(prices.size(), 0);
        
        int minIdx = 0;
        int tmpMax = 0;
        for (int i = 0; i < prices.size(); i++) {
            profixsToJ[i] = (prices[i] - prices[minIdx]) > 0 ? (prices[i] - prices[minIdx]) : 0;
            if (profixsToJ[i] > tmpMax) {
                tmpMax = profixsToJ[i];
            } else {
                profixsToJ[i] = tmpMax;
            }
            
            if (prices[i] < prices[minIdx]) {
                minIdx = i;
            }
        }
        
        int maxIdx = prices.size() - 1;
        tmpMax = 0;
        for (int i = prices.size() - 1; i >= 0; i--) {
            profixsStartI[i] = (prices[maxIdx] - prices[i]) > 0 ? (prices[maxIdx] - prices[i]) : 0;
            if (profixsStartI[i] > tmpMax) {
                tmpMax = profixsStartI[i];
            } else {
                profixsStartI[i] = tmpMax;
            }

			if (prices[i] > prices[maxIdx]) {
                maxIdx = i;
            }
        }
        
        int maxProfit = profixsToJ[prices.size() - 1];
        for (int i = 1; i < prices.size() - 1; i++) {
            int left = profixsToJ[i];
            int right = profixsStartI[i];
            if (left + right > maxProfit) {
                maxProfit = left + right;
            }
        }
        return maxProfit;
    }
};