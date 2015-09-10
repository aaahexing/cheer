/***********************
Count Primes : https://leetcode.com/problems/count-primes/

Description:
Count the number of prime numbers less than a non-negative number, n.
**/

//time complexity: O(nloglogn)
//space complexity: O(n)
int countPrimes(int n) {
	vector<bool> primeTable(n, true);
	int count = 0;
	for (int i = 2; i * i < n; i++) {
		if (!primeTable[i]) {
			continue;
		}
		for (int j = i * i; j < n; j += i) {
			primeTable[j] = false;
		}
	}

	for (int i = 2; i < n; i++) {
		count += primeTable[i] ? 1 : 0;
	}

	return count;
}

//time complexity: O(n^(1/2))
//space complexity: O(1)
bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i * i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}