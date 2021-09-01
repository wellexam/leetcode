#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

string longestPalindrome(string s)
{
    const int len = s.length();
    string ans;
    for (int i = len; i > 0; --i)
    {
        for (int j = 0; j <= len - i; ++j)
        {
            bool is_break = false;
            for (int k = j; k < i + j; ++k)
            {
                if (k > i - k + 2 * j - 1)
                    break;
                if (s[k] != s[i - k + 2 * j - 1])
                {
                    is_break = true;
                    break;
                }
            }
            if (!is_break)
            {
                for (int l = 0; l < i; ++l)
                    ans.push_back(s[l + j]);
                return ans;
            }
        }
    }
    return ans;
}

int main()
{
    cout << longestPalindrome("aacabdkacaa");
}