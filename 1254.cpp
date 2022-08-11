#include "regular_headers.hpp"

unordered_map<int, int> fa;

int find(int x) {
    if (fa[x] == x) {
        return fa[x];
    } else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void union_(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    fa[y] = x;
}

inline int _hash(int x, int y) {
    return (x << 10) + y;
}

int closedIsland(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (!grid[i][j]) {
                fa[_hash(i, j)] = _hash(i, j);
            }
        }
    }
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0) {
                if (i > 0 && !grid[i - 1][j]) {
                    union_(_hash(i, j), _hash(i - 1, j));
                }
                if (i < grid.size() - 1 && !grid[i + 1][j]) {
                    union_(_hash(i, j), _hash(i + 1, j));
                }
                if (j > 0 && !grid[i][j - 1]) {
                    union_(_hash(i, j - 1), _hash(i, j));
                }
                if (j < grid[0].size() - 1 && !grid[i][j + 1]) {
                    union_(_hash(i, j), _hash(i, j + 1));
                }
            }
        }
    }
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (!grid[i][j]) {
                find(_hash(i, j));
            }
        }
    }
    unordered_set<int> filter;
    for (auto &i : fa) {
        filter.insert(i.second);
    }
    for (int i = 0; i < grid.size(); i++) {
        if (!grid[i][0]) {
            filter.erase(fa[_hash(i, 0)]);
        }
        if (!grid[i][grid[0].size() - 1]) {
            filter.erase(fa[_hash(i, grid[0].size() - 1)]);
        }
    }
    for (int j = 0; j < grid[0].size(); j++) {
        if (!grid[0][j]) {
            filter.erase(fa[_hash(0, j)]);
        }
        if (!grid[grid.size() - 1][j]) {
            filter.erase(fa[_hash(grid.size() - 1, j)]);
        }
    }
    return filter.size();
}

int main() {
    vector<vector<int>> grid{{0, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 1, 0, 1},
                             {1, 0, 0, 1, 0, 1, 0, 1}, {1, 1, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 1, 1, 1, 1, 1, 1}};
    cout << closedIsland(grid);
    return 0;
}