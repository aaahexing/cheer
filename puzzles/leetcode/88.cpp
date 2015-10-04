/***********************************
Merge Sorted Array: https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
**/

//@time complexity: O(n)
//@space complexity: O(1)
//@2A, wrote while loop into if condition caused the first failure...
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int end1 = m - 1;
    int end2 = n - 1;
    int pos = m + n - 1;
    while (end2 >= 0 && end1 >= 0) {
        if (nums2[end2] >= nums1[end1]) {
            nums1[pos] = nums2[end2];
            end2--;
        } else {
            nums1[pos] = nums1[end1];
            end1--;
        }
        pos--;
    }
        
    while (end2 >= 0) {
        nums1[pos--] = nums2[end2--];
    }
}
