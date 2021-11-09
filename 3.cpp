#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
        return 0;
    }
    int length = 0;
    unordered_map<char, bool> map;
    deque<char> que;
    for (auto &i : s) {
        auto pos = map.find(i);
        if (pos != map.end() && pos->second) {
            length = max(length, int(que.size()));
            auto front = que.front();
            while (front != i) {
                map[front] = false;
                que.pop_front();
                front = que.front();
            }
            que.pop_front();
            que.emplace_back(i);
        } else {
            map[i] = true;
            que.emplace_back(i);
        }
    }
    length = max(length, int(que.size()));
    return length;
}