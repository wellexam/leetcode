#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class slide
{
public:
    int begin = 9;
    char store[10] = {};
    string str = "0123456789";

    string &add(char);
};

string &slide::add(char c)
{
    store[begin] = c;
    begin = (begin + 1) % 10;
    int count = 0;
    for (int i = begin; i < 10; ++i)
        str[count++] = store[i];
    for (int i = 0; i < begin; ++i)
        str[count++] = store[i];
    return str;
}

vector< string > findRepeatedDnaSequences(string s)
{
    const int len = s.length();
    vector< string > ans;
    if (len <= 10)
        return ans;
    unordered_map< string, int > map;
    slide window;
    for (int i = 0; i < 9; ++i)
        window.store[i] = s[i];
    for (int i = 9; i < len; ++i)
        ++map[window.add(s[i])];
    for (auto &i: map)
        if (i.second > 1)
            ans.push_back(i.first);
    return ans;
}