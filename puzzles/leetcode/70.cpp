/****************************
Climbing Stairs: https://leetcode.com/problems/climbing-stairs/

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
**/

//@time complexity: O(n)
//@space complexity: O(n)
//@1A
int climbStairs(int n) {
    if (n <= 1) {
        return n;
    } 
    vector<int> climbWay(n);
    climbWay[0] = 1;
    climbWay[1] = 2;
    for (int i = 2; i < n; i++) {
        climbWay[i] = climbWay[i - 1] + climbWay[i - 2];
    }
        
    return climbWay[n - 1];
}
