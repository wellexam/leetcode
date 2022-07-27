#include "regular_headers.hpp"

int calculate(string s) {
    stack<int> sign;
    stack<int> ops;
    unordered_map<char, int> umap{{'+', 1}, {'-', -1}};
    ops.push(1);
    sign.push(1);
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        int num = 0;
        bool flag = false;
        while (ch <= '9' && ch >= '0') {
            num = num * 10 + (ch - '0');
            flag = true;
            if (i < s.size() - 1) {
                ch = s[++i];
            } else {
                ++i;
                break;
            }
        }
        if (flag) {
            ans += ops.top() * num;
            --i;
            continue;
        }
        if (ch == ' ')
            continue;
        if (ch == '(') {
            sign.push(sign.top() * ops.top());
            ops.push(sign.top());
        } else if (ch == ')') {
            sign.pop();
        } else {
            ops.push(sign.top() * umap[ch]);
        }
    }
    return ans;
}

int main() {
    auto s = "- (3 + (4 + 5))";
    cout << calculate(s);
    return 0;
}