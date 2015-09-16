/********************************
Min Stack : https://leetcode.com/problems/min-stack/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time. 
• push(x) -- Push element x onto stack. 
• pop() -- Removes the element on top of the stack. 
• top() -- Get the top element. 
• getMin() -- Retrieve the minimum element in the stack. 
**/

class MinStack {
public:
	//@time complexity: O(1)
    void push(int x) {
        s1.push(x);
        if (s2.empty()) {
            s2.push(x);
        } else {
            if (x <= s2.top()) {
                s2.push(x);
            }
        }
    }

	//@time complexity: O(1)
    void pop() {
        int top = s1.top();
        s1.pop();
        if (s2.top() == top) {
            s2.pop();
        }
    }

	//@time complexity: O(1)
    int top() {
        return s1.top();
    }

	//@time complexity: O(1)
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};