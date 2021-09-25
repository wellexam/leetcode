#include "regular_headers.hpp"

using namespace std;

int jump(vector<int> &nums) {
    int n = nums.size();
    if (n <= 2) {
        return n - 1;
    }
    vector<int> reachable(n, -1);
    reachable[0] = 0;
    reachable[1] = 0;
    int current = 2;
    while (current < n) {
        int hoops = 10001;
        for (int i = reachable[current - 1]; i < current; ++i) {
            if (nums[i] + i >= current) {
                reachable[current] = i;
                break;
            }
        }
        ++current;
    }
    int hoops = 0;
    current = n - 1;
    while (current >= 0) {
        if (reachable[current] == 0) {
            ++hoops;
            break;
        }
        current = reachable[current];
        ++hoops;
    }
    return hoops;
}