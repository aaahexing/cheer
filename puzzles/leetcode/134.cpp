/*****************************
Gas Station: https://leetcode.com/problems/gas-station/

There are N gas stations along a circular route, where the amount of gas at station i is gas[i]. 
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations. 
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1. 
**/

//@time complexity: O(n)
//@space complexity: O(n), can be optimized to O(1)
//@1A
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	if (gas.size() == 1) {
		return gas[0] >= cost[0] ? 0 : -1;
	}

	vector<int> sub(gas.size());
	for (int i = 0; i < gas.size(); i++) {
		sub[i] = gas[i] - cost[i];
	}

	for (int start = 0; start < gas.size();) {
		int sum = 0;
		for (int then = start; then < start + gas.size(); then++) {
			sum += sub[then % gas.size()];
			if (sum < 0) {
				start = then + 1 % gas.size();
				break;
			}
		}
		if (sum >= 0) {
			return start;
		}
	}

	return -1;
}