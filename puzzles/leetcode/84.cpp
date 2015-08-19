/**
desc: Leetcode 84: Largest Rectangle in Histogram(https://leetcode.com/problems/largest-rectangle-in-histogram/)
*/


/**
* @desc: first solotion
* @time complexity: O(n^3)
* @space compleixty: O(1)
* @errMsg: time limit exceeded
*/
int largestRectangleArea(vector<int>& height) {
	int res = 0;
	for (int start = 0; start < height.size(); start++) {
		for (int end = 0; end < height.size(); end++) {
			int minPos = findMin(height, start, end);
			int tmpRes = height[minPos] * (end - start + 1);
			if (tmpRes > res) {
				res = tmpRes;
			} 
		}
	}

	return res;
}

int findMin(vector<int> & height, int start, int end) {
	int pos = start;
	for (int i = start; i <= end; i++) {
		if (height[i] < height[pos]) {
			pos = i;
		}
	}

	return pos;
}

/**
*@desc: second solution
*@time complexity: O(n^2) in worst case
*@space compleixty: O(1)
*@errMsg: time limit exceeded
*/
int largestRectangleArea(vector<int>& height) {
	return findLargestRectangleArea(height, 0, height.size()-1);
}

int findLargestRectangleArea(vector<int> & height, int start, int end) {
	if (start > end) {
		return 0;
	}

	int minPos = findMin(height, start, end);
	int tmpRes = height[minPos] * (end - start + 1);
	int tmpResLeft = findLargestRectangleArea(height, start, minPos-1);
	int tmpResRight = findLargestRectangleArea(height, minPos+1, end);

	int ret = tmpRes > tmpResLeft ? tmpRes : tmpResLeft;
	ret = ret > tmpResRight ? ret : tmpResRight;

	return ret;
}

int findMin(vector<int> & height, int start, int end) {
	int pos = start;
	for (int i = start; i <= end; i++) {
		if (height[i] < height[pos]) {
			pos = i;
		}
	}

	return pos;
}

/**
* @desc: third solotion
* @time complexity: O(n), since mostly O(n) element would be poped out of the stack, so the total time complexity of while loop is O(n)
* @space compleixty: O(n)
* @errMsg: accepted
*/
int largestRectangleArea(vector<int>& height) {
	int maxArea = 0;
	int area;
	int top, i;
	stack<int> s;

	for (i = 0; i < height.size(); i++) {
		while (!s.empty()) {
			top = s.top();
			if (height[i] < height[top]) {
				s.pop();
				if (s.empty()) {
					area = i * height[top];
				} else {
					area = (i - s.top() -1) * height[top];
				}

				if (area > maxArea) {
					maxArea = area;
				}
			} else {
				break;
			}
		}
		s.push(i);
	}

	while (!s.empty()) {
		top = s.top();
		s.pop();
		if (s.empty()) {
			area = i * height[top];
		} else {
			area = (i - s.top() -1) * height[top];
		}
		if(area > maxArea) {
			maxArea = area;
		}
	}

	return maxArea;
}

/**
* @desc: forth solotion, by adding a sentinal at the end of the height array, 
*        we can promise the original value is all out of stack, thus all situation is considered and the code is more compact.
* @time complexity: O(n), since mostly O(n) element would be poped out of the stack, so the total time complexity of while loop is O(n)
* @space compleixty: O(n)
* @errMsg: time limit exceeded
*/
int largestRectangleArea(vector<int>& height) {
        int maxArea = 0;
        int area;
        int top, i;
        height.push_back(-1);
        stack<int> s;
        
        for (i = 0; i < height.size(); i++) {
            while (!s.empty()) {
                top = s.top();
                if (height[top] > height[i]) {
                    s.pop();
                    area = s.empty() ? i * height[top] : (i - s.top() - 1) * height[top];
                    if (area > maxArea) {
                       maxArea = area; 
                    }
                } else {
                    break;
                }
            }
            
            s.push(i);
        }
        
        return maxArea;
    }