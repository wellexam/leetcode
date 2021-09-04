#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int findTheWinner(int n, int k) {
    vector<int> que(n);
    for (int i = 0; i < n; ++i)
        que[i] = i + 1;
    int begin = 0;
    while (que.size() > 1) {
        int count = 1;
        while (count < k) {
            ++begin;
            if (begin == que.size())
                begin = 0;
            ++count;
        }
        int old_size = que.size();
        que.erase(que.begin() + begin);
        if (begin == old_size - 1)
            begin = 0;
    }
    return que[0];
}