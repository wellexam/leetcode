#include <iostream>
#include <vector>

using namespace std;

vector< vector< int>> generateMatrix(int n)
{
    vector< vector< int>> mat;
    mat.reserve(n*n);
    vector<int> temp;
    temp.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        temp.push_back(0);
    }
    for (int i = 0; i < n; ++i)
    {
        mat.push_back(temp);
    }
    int count = 1;
    for (int i = 0; i < (n / 2) + (n % 2); ++i)
    {
        for (int y = i; y <= n - 1 - i; ++y)
        {
            mat[i][y] = count++;
        }
        for (int x = i + 1; x <= n - 1 - i; ++x)
        {
            mat[x][n - 1 - i] = count++;
        }
        for (int y = n - 1 - i - 1; y >= i; --y)
        {
            mat[n - 1 - i][y] = count++;
        }
        for (int x = n - 1 - i - 1; x > i; --x)
        {
            mat[x][i] = count++;
        }
    }
    return mat;
}

int main()
{
    auto ans = generateMatrix(5);
    for (auto i: ans)
    {
        for (auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}