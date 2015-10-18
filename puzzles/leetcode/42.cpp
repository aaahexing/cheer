/****************************************
Trapping Rain Water: https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 
For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
**/

//@time complexity: O(n)
//@space complexity: O(n)
int trap(vector<int>& height) {
	if (height.size() <= 2) {
		return 0;
	}
	vector<int> maxLeft(height.size(), 0);
	vector<int> maxRight(height.size(), 0);
	vector<int> trap(height.size(), 0);
	for (int i = 1; i < height.size(); i++) {
		maxLeft[i] = max(height[i - 1], maxLeft[i - 1]);
	}
	for (int i = height.size() - 2; i >= 0; i--) {
		maxRight[i] = max(height[i + 1], maxRight[i + 1]);
	}
	for (int i = 1; i < height.size() - 1; i++) {
		trap[i] = min(maxLeft[i], maxRight[i]) - height[i];
		trap[i] = trap[i] < 0 ? 0 : trap[i];
	}
	int max = 0;
	int curTrap = 0;
	for (int i = 1; i < height.size(); i++) {
		if (trap[i] == 0) {
			if (curTrap > max) {
				max = curTrap;
			}
		} else {
			curTrap += trap[i];
		}
	}
	return max; 
}