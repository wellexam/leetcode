#include "regular_headers.hpp"

using namespace std;

map<int, vector<string>> str_table;

void str_generator(int n, int target, string str) {
    if (!n) {
        str += ")";
        str_table[target].push_back(str);
        return;
    }
    if (n != target) {
        for (int i = 1; i <= n; ++i) {
            for (auto &s : str_table[i]) {
                str_generator(n - i, target, str + s);
            }
        }
    }
    if (n == target) {
        str_generator(n - 1, target, "(");
    }
}

void generator(int n, int target, const string& str) {
    if (n <= 1) {
        if (n == 1) {
            str_table[target].push_back(str + "()");
        } else {
            str_table[target].push_back(str);
        }
        return;
    } else {
        for (int i = 1; i <= n && i < target; ++i) {
            for (auto &s : str_table[i]) {
                generator(n - i, target, str + s);
            }
        }
    }
}

vector<string> generateParenthesis(int n) {
    if (n == 1) {
        return {"()"};
    }
    str_table[1].push_back({"()"});
    for (int i = 2; i <= n; ++i) {
        str_generator(i, i, "");
    }
    generator(n, n, "");
    return str_table[n];
}

int main() {
    for (auto &i : generateParenthesis(1)) {
        cout << i << endl;
    }
}