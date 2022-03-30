#include "regular_headers.hpp"

using namespace std;

int get(vector<int> &ans, int n) {
    if (ans[n] != -1) {
        return ans[n];
    }
    ans[n] = 0;
    for (int i = 1; i <= n; i++) {
        ans[n] += get(ans, i - 1) * get(ans, n - i);
    }
    return ans[n];
}

int numTrees(int n) {
    vector<int> ans(n + 1, -1);
    ans[0] = 1;
    ans[1] = 1;
    return get(ans, n);
}

int main() {
    cout << numTrees(3);
    return 0;
}