/*****************************
Find Peak Element: https://leetcode.com/problems/find-peak-element/

A peak element is an element that is greater than its neighbors.
Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that num[-1] = num[n] = -∞.
For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
**/

//@time complexity: O(n)
//@space complexity: O(1)
int findPeakElement(vector<int>& nums) {
    int before, cur, then;
    for(int cur = 0; cur < nums.size(); cur++) {
        before = cur - 1;
        then = cur + 1;
        if ((before < 0 || nums[cur] > nums[before]) && (then >= nums.size() || nums[cur] > nums[then])) {
            return cur;
        }
    }
        
    return -1;
}

//@desc: divide and conquer    
//@time complexity: O(logn) 
//@space complexity: O(1)
int findPeakElement(vector<int>& nums) {
    if (nums.size() <= 0) {
        return -1;
    }
        
    int start = 0, end = nums.size() - 1;
        
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if ((mid == 0 || nums[mid] >= nums[mid - 1]) && (mid == nums.size() -1 || nums[mid] >= nums[mid + 1])) {
            return mid;
        } else if (nums[mid + 1] > nums[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
        
    return -1;
}
