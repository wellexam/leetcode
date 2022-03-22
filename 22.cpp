#include "regular_headers.hpp"

using namespace std;

vector<vector<string>> table;

void get(int n) {
    if (!table[n].empty()) {
        return;
    }
    for (int i = 1; i <= n; i++) {
        get(i - 1);
        get(n - i);
        for (auto &left : table[i - 1]) {
            for (auto &right : table[n - i]) {
                table[n].push_back('(' + left + ')' + right);
            }
        }
    }
    return;
}

vector<string> generateParenthesis(int n) {
    table = vector<vector<string>>(n + 1);
    table[0].push_back("");
    get(n);
    return table[n];
}

int main() {
    for (auto &i : generateParenthesis(5)) {
        cout << i << endl;
    }
}