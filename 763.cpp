#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> partitionLabels(string s) {
    vector<pair<int, int>> map(26, {-1, -1});
    const int len = s.length();
    for (int i = 0; i < len; ++i)
    {
        if (map[s[i] - 'a'].first == -1)
        {
            map[s[i] - 'a'].first = i;
            map[s[i] - 'a'].second = i;
        }
        else
            map[s[i] - 'a'].second = i;
    }
    sort(map.begin(), map.end());
    if (map.begin()->first == -1)
    {
        auto first = map.begin();
        int i = 1;
        for (; i < 26; ++i)
            if (map[i].first != -1)
                break;
        auto last = map.begin() + i;
        map.erase(first, last);
    }
    int first = 0, last = map[0].second;
    vector<int> arr;
    const int length = map.size();
    for (int i = 1; i < length; ++i)
    {
        if (map[i].first < last)
            last = max (map[i].second, last);
        else
        {
            arr.push_back(last - first + 1);
            first = map[i].first;
            last = map[i].second;
        }
    }
    arr.push_back(last - first + 1);
    return arr;
}

int main()
{
    auto ans = partitionLabels("caedbdedda");
    for (auto i: ans)
        cout << i << " ";
    return 0;
}