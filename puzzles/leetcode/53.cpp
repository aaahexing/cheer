/***********************************
Maximum Subarray : https://leetcode.com/problems/maximum-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest sum. 
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6. 
**/

//@time complexity: O(nlogn)
//@space complexity: O(1)
//@1A
class Solution {
public:
    int maxSubArray(vector<int> & A) {
        if (A.size() <= 0) {
            return 0;
        }
        return maxSubArray(A, 0, A.size() - 1);
    }
    
    int maxSubArray(vector<int> & A, int start, int end) {
        if (end == start) {
            return A[start];
        }
        
        int mid = start + (end - start) / 2;
        int leftMax = maxSubArray(A, start, mid);
        int rightMax = maxSubArray(A, mid + 1, end);
        int ret = max(leftMax, rightMax);
        
        int midLeftMax = A[mid];
        int tmp = A[mid];
        for (int i = mid - 1; i >= start ; i--) {
            tmp = tmp + A[i];
            if (tmp > midLeftMax) {
                midLeftMax = tmp;
            }
        }
        int midRightMax = A[mid];
        tmp = A[mid];
        for (int i = mid + 1; i <= end; i++) {
            tmp += A[i];
            if (tmp > midRightMax) {
                midRightMax = tmp;
            }
        }
        int midMax = midLeftMax + midRightMax - A[mid];
        ret = max(ret, midMax);
        
        return ret;
    }
};