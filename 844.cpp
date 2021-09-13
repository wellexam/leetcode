#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool backspaceCompare(string s, string t) {
    stack<char> a, b;
    for (auto &i : s) {
        if (i != '#') {
            a.push(i);
        } else if (!a.empty()) {
            a.pop();
        }
    }
    for (auto &i : t) {
        if (i != '#') {
            b.push(i);
        } else if (!b.empty()) {
            b.pop();
        }
    }
    if (a.size() != b.size()) {
        return false;
    } else {
        while (!a.empty()) {
            if (a.top() != b.top()) {
                return false;
            } else {
                a.pop();
                b.pop();
            }
        }
    }
    return true;
}