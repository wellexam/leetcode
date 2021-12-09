#include "regular_headers.hpp"

using namespace std;

int rand7();

int rand10() {
    int a = rand7(), b = rand7();
    while (a > 5) {
        a = rand7();
    }
    while (b > 6) {
        b = rand7();
    }
    b %= 2;
    return a + b * 5;
}