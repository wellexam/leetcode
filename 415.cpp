#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Interger {
public:
    int nums[5101]{};
    int digits = 0;
    int carry = 0;

    void str2num(string &);

    string num2str();

    Interger operator+(Interger &b);
};

void Interger::str2num(string &str) {
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        nums[len - i] = str[i] - '0';
    }
    digits = len;
}

Interger Interger::operator+(Interger &b) {
    Interger res;
    for (int i = 0; i <= max(this->digits, b.digits); ++i) {
        auto temp = this->nums[i] + b.nums[i] + res.carry;
        res.nums[i] = temp % 10;
        if (temp > 9)
            res.carry = 1;
        else
            res.carry = 0;
    }
    if (res.carry) {
        res.digits = max(this->digits, b.digits) + 1;
        res.nums[res.digits] = 1;
    } else
        res.digits = max(this->digits, b.digits);
    return res;
}

string Interger::num2str() {
    string str;
    for (int i = this->digits; i > 0; --i) {
        str.push_back(this->nums[i] + '0');
    }
    return str;
}

string addStrings(string num1, string num2) {
    Interger a, b;
    a.str2num(num1);
    b.str2num(num2);
    auto ans = a + b;
    return ans.num2str();
}

int main() {
    cout << addStrings("12345", "23456");
    return 0;
}