/*********************
Kth Largest Element in an Array : https://leetcode.com/problems/kth-largest-element-in-an-array/

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element. 
For example,
Given [3,2,1,5,6,4] and k = 2, return 5. 
**/

//time complexity: O(n) on average
//space complexity: O(1) TT
int findKthLargest(vector<int>& nums, int k) {
	return findKthLargest(nums, 0, nums.size() -1, k);
}

int findKthLargest(vector<int> & nums, int start, int end, int k){
	int size = end - start + 1;
	int pivot = getPivot(size) + start;
	int pivotIdx = getPivotIdx(nums, start, end, pivot);


	if(pivotIdx == nums.size() - k) {
		return nums[pivotIdx];
	} else if (pivotIdx < nums.size() - k) {
		return findKthLargest(nums, pivotIdx + 1, end, k);
	} else {
		return findKthLargest(nums, start, pivotIdx - 1, k);
	}
}

int getPivot(int size) {
	srand(time(NULL));
	return rand() % size;
}

int getPivotIdx(vector<int> & nums, int start, int end, int pivot) {
	swap(nums[start], nums[pivot]);
	int low = start + 1, high = end;
	while (low <= high) {
		while (nums[low] <= nums[start] && low <= end) {low++;}
		while (nums[high] >= nums[start] && high >= start) {high--;}
		if (low <= high) {
			swap(nums[low], nums[high]);
		}
	}
	swap(nums[low-1], nums[start]);

	return low-1;
}

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}