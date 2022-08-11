#include "regular_headers.hpp"

vector<vector<string>> cache;

vector<string> &generate(int i) {
    if (!cache[i].empty()) {
        return cache[i];
    }
    for (int x = 0; x < i; x++) {
        auto a = generate(x);
        auto b = generate(i - 1 - x);
        vector<string> temp_ans;
        string temp;
        temp.push_back('(');
        for (auto &str : a) {
            temp += str;
            temp.push_back(')');
            temp_ans.push_back(temp);
            temp.resize(temp.size() - str.size() - 1);
        }
        for (auto &str : b) {
            for (auto ans : temp_ans) {
                ans += str;
                cache[i].push_back(ans);
            }
        }
    }
    return cache[i];
}

vector<string> generateParenthesis(int n) {
    cache = vector<vector<string>>(n + 1);
    cache[0] = {""};
    generate(n);
    return cache.back();
}

int main() {
    for (auto &i : generateParenthesis(5)) {
        cout << i << endl;
    }
}