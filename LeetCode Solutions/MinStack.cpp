
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.

class MinStack {
public:
    void push(int x) {
        m_stack.push(x);
        
        if (m_min.size() == 0) {
            m_min.push(x);
        }
        else if (x <= m_min.top()) {
            m_min.push(x);
        }
    }

    void pop() {
        if (m_min.top() == m_stack.top()) {
            m_min.pop();
        }
        m_stack.pop();
    }

    int top() {
        return m_stack.top();
    }

    int getMin() {
        return m_min.top();
    }
    
private:
    stack<int> m_stack;
    stack<int> m_min;
};