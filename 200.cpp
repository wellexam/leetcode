#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int find_father(int son, vector<int> &father) {
    if (son != father[son]) {
        father[son] = find_father(father[son], father);
    }
    return father[son];
}

bool connect(int son_1, int son_2, vector<int> &father) {
    auto die_2 = find_father(son_2, father);
    auto die_1 = find_father(son_1, father);
}

int numIslands(vector<vector<char>> &grid) {
    unordered_map<pair<int, int>, int> map;
    int m = grid.size(), n = grid[0].size();
    int size = m * n;
    vector<int> father(size, -1);
}