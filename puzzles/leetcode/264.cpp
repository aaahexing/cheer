/*********
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
**/

//@desc: kth ugly number is min of {2*l1, 3*l2, 5*l3}, l1, l2, l3 represents the previous ugly number
//@time complexity: O(n)
//@space comlexity: O(n)
int nthUglyNumber(int n) {
    int pos2 = 0, pos3 = 0, pos5 = 0;
    vector<int> res(n, 1);
        
    for (int i = 1; i < n; i++) {
        res[i] = min(res[pos2] * 2, min(res[pos3] * 3, res[pos5] * 5));
        if (res[i] == res[pos2] * 2) {
            pos2++;
        }
        if (res[i] == res[pos3] * 3) {
            pos3++;
        }
        if (res[i] == res[pos5] * 5) {
            pos5++;
        }
    }
        
    return res[n-1];
}
