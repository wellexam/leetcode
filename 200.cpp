#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int find_father(int son, vector< int > &father)
{
    if (son != father[son])
    {
        father[son] = find_father(father[son], father);
    }
    return father[son];
}

int merge(int son_1, int son_2, vector< int > &father)
{
    auto die = min(find_father(son_1, father), find_father(son_2, father));
    //auto die = min(son_1, son_2);
    father[son_1] = die;
    father[son_2] = die;
    return die;
}

int numIslands(vector< vector< char>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int size = m * n;
    unordered_map< int, bool > count;
    vector< int > father(size, -1);
    unordered_map< int, vector< int>> map;
    for (int pos = 0; pos < size; ++pos)
    {
        int x = pos / n;
        int y = pos % n;
        if (grid[x][y] == '0')
        {
            continue;
        }
        if (father[pos] == -1)
        {
            auto find_father = 0;
            auto die_1 = -1, die_2 = -1;
            if (y - 1 >= 0 && father[pos - 1] != -1)
            {
                die_1 = father[pos - 1];
                ++find_father;
            }
            if (x - 1 >= 0 && father[pos - n] != -1)
            {
                die_2 = father[pos - n];
                ++find_father;
            }
            if (!find_father)
            {
                father[pos] = pos;
            }
            else
            {
                if (find_father == 1)
                {
                    father[pos] = max(die_1, die_2);
                }
                else
                {
                    father[pos] = merge(die_1, die_2, father);
                }
            }
        }
    }
    for (int pos = 0; pos < size; ++pos)
    {
        if (father[pos] >= 0)
        {
            father[pos] = find_father(pos, father);
            count[father[pos]] = true;
        }
    }
    //for (int pos = size - 1; pos >= 0; --pos) {
    //    if (father[pos] >= 0)
    //    {
    //        father[pos] = find_father(pos, father);
    //        count[father[pos]] = true;
    //    }
    //}
    //int temp = 0;
    //vector<pair<int, int>> shit;
    //for (auto &i: count)
    //{
    //    ++temp;
    //    std::cout << temp << " : " << i.first / n << ", " << i.first % n << " " << i.first << endl;
    //    shit.emplace_back(i.first / n, i.first % n);
    //}
    //sort(shit.begin(), shit.end());
    //for (auto &i : shit) {
    //    cout << i.first << " " << i.second << endl;
    //}
    return count.size();
}

int main()
{
    vector< vector< char>> grid{
            {'0', '0', '1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '0'},
            {'0', '1', '0', '0', '0', '0', '1', '1', '0', '0', '0', '1', '0', '0', '1', '1', '0', '0', '0', '0'},
            {'1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1', '1', '1', '1', '0'},
            {'1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1', '1', '1', '1', '1', '1', '1'},
            {'0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '1', '1', '1', '0', '1', '0', '0', '0', '0', '0'},
            {'0', '1', '1', '1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '0', '1', '0', '1', '1', '0', '0'},
            {'0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0'},
            {'0', '1', '1', '0', '0', '0', '0', '0', '1', '0', '1', '1', '0', '1', '1', '0', '0', '1', '0', '0'},
            {'0', '0', '1', '1', '1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '1'},
            {'1', '1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '1', '1', '0', '0', '1', '0', '1', '1', '0'},
            {'0', '0', '0', '0', '0', '0', '1', '0', '1', '1', '0', '0', '1', '0', '1', '1', '1', '1', '0', '1'},
            {'0', '0', '1', '1', '0', '0', '1', '0', '1', '0', '0', '1', '0', '0', '1', '0', '0', '1', '0', '1'},
            {'0', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '1', '0', '0', '1', '1', '0', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1'},
            {'1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1', '1', '0'},
            {'1', '0', '1', '1', '1', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '1', '1'},
            {'1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '1', '1'},
            {'0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1', '0', '1', '1', '0', '1', '0', '1'},
            {'1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '1', '1', '1', '1'},
            {'0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0'}};
    std::cout << numIslands(grid);
    return 0;
}