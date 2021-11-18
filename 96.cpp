#include "regular_headers.hpp"

using namespace std;

int recursive(int begin, int end, vector<int> &map) {
    if (end <= begin) {
        return 1;
    }
    if (map[end - begin]) {
        return map[end - begin];
    }
    auto count = 0;
    for (int i = begin; i <= end; ++i) {
        int temp = 1;
        temp *= recursive(begin, i - 1, map);
        temp *= recursive(i + 1, end, map);
        count += temp;
    }
    map[end - begin] = count;
    return count;
}

int numTrees(int n) {
    vector<int> map(n, 0);
    return recursive(1, n, map);
}