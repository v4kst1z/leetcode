//
// Created by v4kst1z on 2021/3/23.
//

class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for(int id = 1; id < q.size(); id++) {
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        for(int id = 1; id < q.size(); id++) {
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        q.push(res);
        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
