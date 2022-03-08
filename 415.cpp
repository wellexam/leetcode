#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addStrings(string num1, string num2) {
    bool carry = false;
    if (num1.size() > num2.size()) {
        num1.swap(num2);
    }
    int size1 = num1.size();
    int size2 = num2.size();
    for (int i = 1; i <= size1; i++) {
        int temp = num1[size1 - i] - '0' + num2[size2 - i] - '0';
        if (carry) {
            temp++;
        }
        if (temp > 9) {
            carry = true;
            temp %= 10;
        } else {
            carry = false;
        }
        num2[size2 - i] = temp + '0';
    }
    int i = size1 + 1;
    while (carry && i <= size2) {
        int temp = num2[size2 - i] - '0';
        if (carry) {
            temp++;
        }
        if (temp > 9) {
            carry = true;
            temp %= 10;
        } else {
            carry = false;
        }
        num2[size2 - i] = temp + '0';
        i++;
    }
    if (carry) {
        return string{'1'}.append(num2);
    } else {
        return num2;
    }
}

int main() {
    cout << addStrings("456", "77");
    return 0;
}