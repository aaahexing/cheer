/***********************************
Remove Duplicates from Sorted Array II: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
Given sorted array nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
**/

//-------------------------------solution 1-----------------------------
//@time complexity: O(n)
//@space complexity: O(1)
//@2A
int removeDuplicates(vector<int>& nums) {
    int pos = 0, cur = 0, next = 1, dupFlag = 0;
    if (nums.size() <= 2) {
        return nums.size();
    }
        
    while(cur < nums.size() && next < nums.size()) {
        if (nums[cur] == nums[next]) {
            if (dupFlag == 0) {
                nums[pos++] = nums[cur];
                dupFlag = 1;
            }
            cur = next;
            next++;
        } else {
            nums[pos++] = nums[cur];
            dupFlag = 0;
            cur = next;
            next = next + 1;
        }
    }
        
    nums[pos++] = nums[cur];
    return pos;
}

//-------------------------------------solution 2---------------------------------
//@universal solution
//@time complexity: O(n)
//@space complexity: O(1)
//@2A
int removeDuplicates(vector<int>& nums) {
    int pos = 0, cur = 0, next = 1, countDup = 1;
    if (nums.size() <= 2) {
        return nums.size();
    }
        
    while(cur < nums.size() && next < nums.size()) {
        if (nums[cur] == nums[next]) {
            countDup++;
            next++;
        } else {
            int count = 0;
            while (countDup > 0 && count < 2) {
                nums[pos++] = nums[cur];
                countDup--;
                count++;
            }
            cur = next;
            next = next + 1;
            countDup = 1;
        }
    }
        
    int count = 0;
    while (countDup > 0 && count < 2) {
        nums[pos++] = nums[cur];
        countDup--;
        count++;
    }
    return pos;
}
