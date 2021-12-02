#include "regular_headers.hpp"

using namespace std;

list<pair<int, int>> table;

int expand(int begin, int end, string &s) {
    while (begin - 1 >= 0 && end + 1 < s.size()) {
        if (s[begin - 1] == '(' && s[end + 1] == ')') {
            begin -= 1;
            end += 1;
        } else {
            break;
        }
    }
    table.emplace_back(begin, end);
    return end;
}

void merge(string &s) {
    int current = 0;
    for (int i = 0; i < s.size();) {
        auto begin = i, end = i;
        if (s[i] == '(') {
            if (i < s.size() - 1 && s[i + 1] == ')') {
                end = i + 1;
                end = expand(begin, end, s);
            }
        }
        i = end + 1;
    }
}

int longestValidParentheses(string s) {
    merge(s);
}