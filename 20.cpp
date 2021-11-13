#include "regular_headers.hpp"

using namespace std;

bool isValid(string s) {
    stack<char> left;
    auto iter = s.cbegin();
    while (iter != s.cend()) {
        if (*iter == '(' || *iter == '{' || *iter == '[') {
            left.push(*iter);
            ++iter;
        } else {
            if (left.empty()) {
                return false;
            }
            if ((*iter == ')' && left.top() == '(') || (*iter == '}' && left.top() == '{') || (*iter == ']' && left.top() == '[')) {
                left.pop();
                ++iter;
            } else {
                return false;
            }
        }
    }
    return left.empty();
}