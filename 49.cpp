#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

vector< vector< string>> groupAnagrams(vector< string > &strs)
{
    unordered_map< string, vector< int>> map;
    int count = 0;
    for (auto &str: strs)
    {
        vector< int > table(26, 0);
        for (auto c: str)
        {
            ++table[c - 'a'];
        }
        string temp;
        temp.reserve(100);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < table[i]; ++j)
                temp.push_back(char(i + 'a'));
        map[temp].push_back(count);
        ++count;
    }
    vector< vector< string>> ans;
    ans.reserve(map.size());
    for (auto &i: map)
    {
        ans.emplace_back();
        auto t = ans.end() - 1;
        for (auto s : i.second)
        {
            t->push_back(strs[s]);
        }
    }
    return ans;
}