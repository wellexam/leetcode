#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int father(int son, unordered_map<int, int> &map, unordered_map<int, bool> &ans) {
    auto iter = map.find(son);
    if (iter == map.end()) {
        ans[son] = true;
        return son;
    }
    int ancestor = father(iter->second, map, ans);
    if (ancestor == -1) {
        return -1;
    } else {
        map[son] = ancestor;
        return ancestor;
    }
}

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
    unordered_map<int, int> map;
    unordered_map<int, bool> ans;
    vector<int> res;
    for (auto &pair : edges) {
        map[pair[1]] = pair[0];
    }
    for (int i = 0; i < n; ++i) {
        father(i, map, ans);
    }
    for (auto &i : ans) {
        res.push_back(i.first);
    }
    return res;
}