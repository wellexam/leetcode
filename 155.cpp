#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class MinStack {
private:
    vector<int> stack;
    vector<int> min_stack;
    int min;
    int top_pos = -1;

public:
    /** initialize your data structure here. */
    MinStack() {
        min = 0x7fffffff;
    }

    void push(int val) {
        stack.push_back(val);
        ++top_pos;
        if (val < min)
            min = val;
        min_stack.push_back(min);
    }

    void pop() {
        stack.erase(stack.end() - 1);
        min_stack.erase(min_stack.end() - 1);
        --top_pos;
        if (top_pos < 0)
            min = 0x7fffffff;
        else
            min = min_stack[top_pos];
    }

    int top() {
        return stack[top_pos];
    }

    int getMin() {
        return min_stack[top_pos];
    }
};

int main() {
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int a = obj->getMin();
    obj->pop();
    a = obj->top();
    a = obj->getMin();
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */