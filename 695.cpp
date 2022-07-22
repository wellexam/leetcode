#include "regular_headers.hpp"

int dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visit) {
    int area = 1;
    visit[x][y] = true;
    if (x > 0 && !visit[x - 1][y] && grid[x - 1][y]) {
        area += dfs(x - 1, y, grid, visit);
    }
    if (x < grid.size() - 1 && !visit[x + 1][y] && grid[x + 1][y]) {
        area += dfs(x + 1, y, grid, visit);
    }
    if (y > 0 && !visit[x][y - 1] && grid[x][y - 1]) {
        area += dfs(x, y - 1, grid, visit);
    }
    if (y < grid.front().size() - 1 && !visit[x][y + 1] && grid[x][y + 1]) {
        area += dfs(x, y + 1, grid, visit);
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>> &grid) {
    vector<vector<bool>> visit(grid.size(), vector<bool>(grid.front().size(), false));
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (!visit[i][j] && grid[i][j]) {
                ans = max(dfs(i, j, grid, visit), ans);
            }
        }
    }
    return ans;
}