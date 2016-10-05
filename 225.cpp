#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    queue<int> q, q2;

    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {

        while (q.size() > 1) {
            q2.push(q.front());
            q.pop();
        }
        q.pop();
        while(q2.size()) {
            q.push(q2.front());
            q2.pop();
        }
    }

    // Get the top element.
    int top() {
        while (q.size() > 1) {
            q2.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        q2.push(res);
        while(q2.size()) {
            q.push(q2.front());
            q2.pop();
        }
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};