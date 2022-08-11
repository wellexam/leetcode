#include "regular_headers.hpp"

int get_digit(int i, int base) {
    return (i % (base * 10)) / base;
}

int digit_triger(int i, int digit, bool up_or_down) {
    int base = 1;
    while (--digit) {
        base *= 10;
    }
    int a = get_digit(i, base);
    if (up_or_down) {
        if (a == 9) {
            return i - 9 * base;
        }
        return i + base;
    } else {
        if (a == 0) {
            return i + 9 * base;
        }
        return i - base;
    }
}

int openLock(vector<string> &deadends, string target) {
    int count = 0;
    unordered_set<int> visited;
    for (auto &str : deadends) {
        visited.insert(atoi(str.c_str()));
    }
    int target_ = atoi(target.c_str());
    deque<int> que, que_next;
    if (visited.count(0)) {
        return -1;
    }
    que.push_back(0);
    while (!que.empty()) {
        while (!que.empty()) {
            auto cur = que.front();
            que.pop_front();
            if (cur == target_) {
                return count;
            }
            for (int i = 1; i <= 4; i++) {
                auto temp = digit_triger(cur, i, true);
                if (!visited.count(temp)) {
                    visited.insert(temp);
                    que_next.push_back(temp);
                }
                temp = digit_triger(cur, i, false);
                if (!visited.count(temp)) {
                    visited.insert(temp);
                    que_next.push_back(temp);
                }
            }
        }
        que.swap(que_next);
        count++;
    }
    return -1;
}