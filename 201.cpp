#include "regular_headers.hpp"

using namespace std;

int rangeBitwiseAnd(int left, int right) {
    auto xor_num = left ^ right, highest_different_digit = 0;
    while (highest_different_digit < 31) {
        if (xor_num >= 0) {
            xor_num = xor_num << 1;
            ++highest_different_digit;
        } else {
            break;
        }
    }
    if (highest_different_digit == 0) {
        return 0;
    }
    int s = -2147483648;
    while (highest_different_digit > 0) {
        --highest_different_digit;
        s = s >> 1;
    }
    return left & s;
}