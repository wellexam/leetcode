#include "regular_headers.hpp"

using namespace std;

void dfs(int current, string &str, stack<char> stack, vector<string> &ans) {
    if (current == 0) {
        return;
    }
    while (current > 0) {
        --current;
        str.push_back('(');
        stack.push(')');
        dfs(current, str, stack, ans);
    }
}

vector<string> generateParenthesis(int n) {
    stack<char> stack_1, stack_2;
    vector<string> ans;
    string str;
}