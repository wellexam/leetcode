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
                begin -= end - (i + 1);
                table.emplace_back(begin, end);
            }
        }
        i = end + 1;
    }
}

void loop(string &s) {
    bool mark = true;
    while (mark) {
        mark = false;
        for (auto iter = table.begin(); iter != table.end();) {
            auto next = iter;
            ++next;
            while (next != table.end()) {
                if (iter->second == next->first - 1) {
                    iter->second = next->second;
                    next = table.erase(next);
                    mark = true;
                } else {
                    break;
                }
            }
            ++iter;
        }
        for (auto &i : table) {
            auto begin = i.first, end = i.second;
            end = expand(begin, end, s);
            if (end != i.second) {
                mark = true;
            }
            begin -= end - i.second;
            i = {begin, end};
        }
    }
}

int longestValidParentheses(string s) {
    merge(s);
    loop(s);
    int ans = 0;
    for (auto &i : table) {
        ans = max(i.second - i.first + 1, ans);
    }
    return ans;
}