#include "regular_headers.hpp"

using namespace std;

// void dfs(int count, string str,int closing_count, vector<string> &ans) {
//     if (!count) {
//         while (closing_count) {
//             --closing_count;
//             str.push_back('c');
//         }
//         ans.emplace_back(str);
//         return;
//     }
//     while (count) {
//         --count;
//         str.push_back('(');
//         ++closing_count;
//         dfs(count, str, closing_count, ans);
//     }
// }

vector<string> generateParenthesis(int n) {
    vector<string> last{"()"};
    if (n == 1) {
        return last;
    }
    --n;
    while (n) {
        vector<string> current;
        for (auto &i : last) {
            current.emplace_back("(" + i + ")");
            current.emplace_back("()" + i);
            current.emplace_back(i + "()");
        }
        current.pop_back();
        --n;
        last = current;
    }
    sort(last.begin(), last.end());
    return last;
}