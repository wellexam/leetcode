#include "regular_headers.hpp"

using namespace std;

int climbStairs(int n) {
    if (n < 3)
        return n;
    int a = 1, b = 2, ans = 1;
    for (int i = 3; i <= n; ++i) {
        ans = a + b;
        a = b;
        b = ans;
    }
    return ans;
}