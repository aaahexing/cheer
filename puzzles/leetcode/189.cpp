/******************************
Rotate Array : https://leetcode.com/problems/rotate-array/

Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 
**/
//---------------------------solution 1-------------------------------
//time complexity: O(n)
//space complexity: O(n)
//1A
void rotate(vector<int>& nums, int k) {
	vector<int> tmp(nums.size());
	for (int i = 0; i < nums.size(); i++) {
		tmp[(i+k)%nums.size()] = nums[i]; 
	}
	nums = tmp;
}

//---------------------------solution 2---------------------------------
//time complexity: O(kn)
//space complexity: O(1)
//TLE
void rotate(vector<int>& nums, int k) {
	int pos = 0, tmp;
	for (int i = nums.size() - (k % nums.size()); i < nums.size(); i++) {
		tmp = nums[i];
		for (int j = nums.size() - k - 1 + pos; j >= pos; j--) {
			nums[j+1] = nums[j];
		}
		nums[pos++] = tmp;
	}
}

//---------------------------solution 3--------------------------------------
//time complexity: O(n)
//space complexity: O(1)
//2A: be specially careful of the following note
void rotate(vector<int>& nums, int k) {
	int start = 0;
	int step = k;
	int size = nums.size();
	for (int i = 0; i < size; i++) {
		swap(nums[start], nums[(start + step) % size]);  //(start + step) % size not step % size
		step += k;
		if (step % size == 0) {                          // this condition must be added 
			start++;
			i++;                                         // in this condition, the last circle one is put in the right pos, so i must plus one
			step = k;
		}
	}
}

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}