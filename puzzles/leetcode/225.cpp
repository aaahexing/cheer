/****************
Implement Stack using Queues: https://leetcode.com/problems/implement-stack-using-queues/

Implement the following operations of a stack using queues. 
• push(x) -- Push element x onto stack. 
• pop() -- Removes the element on top of the stack. 
• top() -- Get the top element. 
• empty() -- Return whether the stack is empty. 
**/

//@desc: always make sure second queue only have one element
class Stack {
public:
    queue<int> first;
    queue<int> second;
    // Push element x onto stack.
    void push(int x) {
        if (!second.empty()) {
            first.push(second.front());
            second.pop();
        }
        
        second.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        second.pop();
        if (first.empty()) {
            return;
        }
        
        while (!first.empty()) {
            second.push(first.front());
            first.pop();
        }
        
        while (second.size() != 1) {
            first.push(second.front());
            second.pop();
        }
    }

    // Get the top element.
    int top() {
        return second.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return first.empty() && second.empty();
    }
};