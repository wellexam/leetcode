#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string s)
{
    unordered_map< char, string > map;
    unordered_map< string, char > map1;
    int pos = 0;
    for (int i = 0; i < pattern.length(); ++i)
    {
        if (pos >= s.length())
            return false;
        string temp;
        while (s[pos] != ' ' && pos < s.length())
        {
            temp.push_back(s[pos]);
            ++pos;
        }
        ++pos;
        if (!map[pattern[i]].empty())
        {
            if (map[pattern[i]] == temp)
            {
                if (map1[temp] == pattern[i])
                    continue;
                else
                    return false;
            }
            else { return false; }
        }
        else
        {
            auto pla = map1.find(temp);
            if (pla != map1.end())
                return false;
            map[pattern[i]] = temp;
            map1[temp] = pattern[i];
        }
    }
    if (pos != s.length() + 1)
        return false;
    return true;
}

int main()
{
    cout << wordPattern("abc", "dog cat dog");
    return 0;
}