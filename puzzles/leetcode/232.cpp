//Implement the following operations of a queue using stacks. 
//push(x) -- Push element x to the back of queue. 
//pop() -- Removes the element from in front of queue. 
//peek() -- Get the front element. 
//empty() -- Return whether the queue is empty

//trial times: one

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        st1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!st2.empty())
        {
            st2.pop();
        }
        else
        {
            while(!st1.empty())
            {
                int tmp = st1.top();
                st1.pop();
                st2.push(tmp);
            }
            st2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if(!st2.empty())
        {
            return st2.top();
        }
        else
        {
            while(!st1.empty())
            {
                int tmp = st1.top();
                st1.pop();
                st2.push(tmp);
            }
            return st2.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if(st1.empty() && st2.empty())
            return true;
        else
            return false;
    }
    
    stack<int> st1,st2;
};