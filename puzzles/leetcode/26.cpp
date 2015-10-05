/************************************
Remove Duplicates from Sorted Array: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
  
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
**/

//@time complexity: O(n)
//@space complexity: O(1)
//@1A
int removeDuplicates(vector<int>& nums) {
    int pos = 0;
    if (nums.size() <= 1) {
        return nums.size();
    }
    int cur = 0, next = 1;
    while (cur < nums.size() && next < nums.size()) {
        if (nums[cur] != nums[next]) {
            nums[pos++] = nums[cur];
            cur = next;
            next++;
        } else {
            next++;
        }
    }
    nums[pos++] = nums[cur];
        
    return pos;
}
