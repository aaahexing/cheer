/**********************************
Next Permutation : https://leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. 
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). 
The replacement must be in-place, do not allocate extra memory. 
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
**/

//@time complexity: O(n)
//@space complexity: O(1)
//@2A
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i-1] < nums[i]) {
                int pos = findFirstLargeIdx(nums, nums[i-1], i);
                swap(nums[i-1], nums[pos]);
                reverse(nums.begin() + i, nums.end());
                return ;
            }
        }
        reverse(nums.begin(), nums.end());
    }
    
    int findFirstLargeIdx(vector<int>& nums, int val, int start) {
        while(start < nums.size() && nums[start] > val) {
            start++;
        }
        return start - 1;
    }
};