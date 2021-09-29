#include "regular_headers.hpp"

using namespace std;

bool isHappy(int n) {
    unordered_map<int, bool> map;
    while (map.find(n) == map.end()) {
        map[n] = true;
        auto sum = 0;
        while (n) {
            auto digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
        if (n == 1) {
            return true;
        }
    }
    return false;
}