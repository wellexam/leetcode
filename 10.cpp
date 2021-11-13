#include "regular_headers.hpp"

using namespace std;

string::const_iterator s_end, p_end;

bool regex(string::const_iterator iter_s, string::const_iterator iter_p) {
    if (iter_s == s_end && iter_p == p_end) {
        return true;
    } else if (iter_s != s_end && iter_p == p_end) {
        return false;
    } else if (iter_s == s_end && iter_p != p_end) {
        if (iter_p + 1 != p_end && *(iter_p + 1) == '*') {
            return regex(iter_s, iter_p + 2);
        }
        return false;
    }
    if (iter_p + 1 != p_end) {
        if (*(iter_p + 1) == '*') {
            if (regex(iter_s, iter_p + 2)) {
                return true;
            }
            if (*iter_s == *iter_p || *iter_p == '.') {
                while (!regex(iter_s + 1, iter_p)) {
                    if (iter_s + 1 != s_end) {
                        ++iter_s;
                        if (*iter_s == *iter_p || *iter_p == '.') {
                            continue;
                        } else {
                            return false;
                        }
                    } else {
                        iter_p += 2;
                        if (iter_p != p_end) {
                            return false;
                        }
                    }
                }
                return true;
            }
        } else {
            if (*iter_s == *iter_p || *iter_p == '.') {
                return regex(iter_s + 1, iter_p + 1);
            } else {
                return false;
            }
        }
    } else {
        if (*iter_s == *iter_p || *iter_p == '.') {
            return regex(iter_s + 1, iter_p + 1);
        } else {
            return false;
        }
    }
    return false;
}

bool isMatch(string s, string p) {
    s_end = s.cend();
    p_end = p.cend();
    return regex(s.cbegin(), p.cbegin());
}

int main() {
    cout << isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c");
}