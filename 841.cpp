#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool canVisitAllRooms(vector<vector<int>> &rooms) {
    vector<bool> accessible(rooms.size(), false);
    deque<int> que;
    int locked_count = rooms.size() - 1;
    for (auto i : rooms[0]) {
        que.push_back(i);
    }
    accessible[0] = true;
    while (!que.empty()) {
        auto key = que.front();
        que.pop_front();
        if (!accessible[key]) {
            accessible[key] = true;
            --locked_count;
            for (auto i : rooms[key]) {
                que.push_back(i);
            }
        }
    }
    if (locked_count) {
        return false;
    }
    return true;
}