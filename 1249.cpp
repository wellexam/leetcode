#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string minRemoveToMakeValid(string s) {
    stack<char> stack_a, stack_b;
    int left_count = 0, right_count = 0;
    for (auto &i : s) {
        if (i == '(')
            ++left_count;
        else if (i == ')') {
            if (left_count <= 0)
                continue;
            --left_count;
        }
        stack_a.push(i);
    }
    while (!stack_a.empty()) {
        char i = stack_a.top();
        stack_a.pop();
        if (i == ')')
            ++right_count;
        else if (i == '(') {
            if (right_count <= 0)
                continue;
            --right_count;
        }
        stack_b.push(i);
    }
    string ans;
    ans.reserve(stack_b.size());
    while (!stack_b.empty()) {
        ans.push_back(stack_b.top());
        stack_b.pop();
    }
    return ans;
}