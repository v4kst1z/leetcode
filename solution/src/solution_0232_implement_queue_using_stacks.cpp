//
// Created by v4kst1z on 2021/3/23.
//

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty()) {
            while (!s1.empty()){
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
        }
        int tmp = s2.top();
        s2.pop();
        return tmp;
    }

    /** Get the front element. */
    int peek() {
        if(s2.empty()){
            while (!s1.empty()){
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
        }
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};