/************************************
Candy : https://leetcode.com/problems/candy/

There are N children standing in a line. Each child is assigned a rating value. 
You are giving candies to these children subjected to the following requirements: 
•Each child must have at least one candy.
•Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give? 
**/

//@time complexity: O(nlogn)
//@space complexity: O(n)
//@1A
int candy(vector<int>& ratings) {
	vector<int> candy(ratings.size(), 0);
	multimap<int, int> m;
	for (int i = 0; i < ratings.size(); i++) {
		pair<int, int> tmp(ratings[i], i);
		m.insert(tmp);
	}

	for (multimap<int, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
		int rate = itr->first;
		int idx = itr->second;
		int leftIdx = idx - 1;
		int rightIdx = idx + 1;
		if (((leftIdx >= 0 && ratings[leftIdx] > rate) || (leftIdx < 0)) && ((rightIdx < ratings.size() && ratings[rightIdx] > rate) || rightIdx == ratings.size())) {
			candy[idx] = 1;
		} else {
			if (leftIdx >= 0 && ratings[leftIdx] <= rate) {
				if (ratings[leftIdx] == rate) {
					candy[idx] = 1;
				} else {
					candy[idx] = candy[leftIdx] + 1;
				}
			}

			if (rightIdx < ratings.size() && ratings[rightIdx] <= rate) {
				if (ratings[rightIdx] == rate) {
					candy[idx] = max(candy[idx], 1);
				} else {
					candy[idx] = max(candy[idx], candy[rightIdx] + 1);
				}
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < candy.size(); i++) {
		ret += candy[i];
	}

	return ret;
}