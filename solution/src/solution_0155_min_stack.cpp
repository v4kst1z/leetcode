//
// Created by v4kst1z on 2021/3/23.
//

class MinStack {
private:
    stack<pair<int, int>> m_stack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        if(!m_stack.size()) {
            m_stack.push(pair<int, int>(val, val));
        } else {
            m_stack.push(pair<int, int>(val, min(val, m_stack.top().second)));
        }
    }

    void pop() {
        if(m_stack.size())
            m_stack.pop();
    }

    int top() {
        return m_stack.top().first;
    }

    int getMin() {
        return m_stack.top().second;
    }
};
