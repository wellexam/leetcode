#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string ans(num1.size() + num2.size(), '0');
    for (int i = 0; i < num1.size(); i++) {
        for (int j = 0; j < num2.size(); j++) {
            int temp = (num1[i] - '0') * (num2[j] - '0') + ans[i + j] - '0';
            int carry = 0;
            if (temp >= 10) {
                carry = temp / 10;
                temp %= 10;
            }
            ans[i + j] = temp + '0';
            int up = 1;
            while (carry) {
                temp = ans[i + j + up] - '0' + carry;
                if (temp >= 10) {
                    carry = 1;
                    temp -= 10;
                } else {
                    carry = 0;
                }
                ans[i + j + up] = temp + '0';
                up++;
            }
        }
    }
    while (!ans.empty() && ans.back() == '0') {
        ans.pop_back();
    }
    if (ans.empty()) {
        ans.push_back('0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cout << multiply("0", "456");
    return 0;
}