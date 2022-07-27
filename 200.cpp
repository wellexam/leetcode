#include "regular_headers.hpp"

using namespace std;

int mask = 0x3FF;

vector<vector<int>> fa;

int find(int pos) {
    int x = pos >> 10;
    int y = pos & mask;
    if (fa[x][y] == pos) {
        return pos;
    } else {
        return fa[x][y] = find(fa[x][y]);
    }
}

void merge(int a, int b) {
    int roota = find(a);
    int rootb = find(b);
    int xa = roota >> 10, ya = roota & mask;
    int xb = rootb >> 10, yb = rootb & mask;
    if (roota != rootb) {
        fa[xa][ya] = rootb;
    }
}

int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    fa = vector<vector<int>>(grid.size(), vector<int>(grid[0].size()));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                fa[i][j] = (i << 10) + j;
            } else {
                fa[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (fa[i][j] != -1) {
                if (i > 0 && fa[i - 1][j] != -1) {
                    merge(fa[i - 1][j], fa[i][j]);
                }
                if (j > 0 && fa[i][j - 1] != -1) {
                    merge(fa[i][j - 1], fa[i][j]);
                }
                if (i < m - 1 && fa[i + 1][j] != -1) {
                    merge(fa[i + 1][j], fa[i][j]);
                }
                if (j < n - 1 && fa[i][j + 1] != -1) {
                    merge(fa[i][j + 1], fa[i][j]);
                }
            }
        }
    }
    unordered_set<int> uset;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (fa[i][j] != -1) {
                uset.insert(find(fa[i][j]));
            }
        }
    }
    return uset.size();
}

int main() {
    vector<vector<char>> grid{{'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '1'}};
    std::cout << numIslands(grid);
    return 0;
}