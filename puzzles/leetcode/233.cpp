#include <iostream>
using namespace std;

//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
//For example:
//Given n = 13,
//Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

//violent solution
//time limited exceeded
int countDigitOne(int n) {
	int count = 0;
	for(int i=1; i<n; i++)
		count += countOne(i);
	return count;
}

int countOne(int n)
{
	int count = 0;
	while(n)
	{
		count += n % 10 == 1 ? 1 : 0;
		n = n/10;
	}
	return count;
}

//time complexity: O(logn)
long long countDigitOne(int n) {
        if(n <= 0)
            return 0;
        long long sum = 0;
        long long fac = 1;            //very important to define this type as long long!! Otherwise, overflow would occur.
        for(; fac * 10 <= n; fac *= 10)
        ;
        
        sum += min(n-fac+1, fac) + (n/fac) * countDigitOne(fac-1) + countDigitOne(n%fac);
        return sum;
    }

int main()
{
	cout << countDigitOne(1410065408)<<endl;
	return 0;
}