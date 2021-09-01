#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector< vector< int>> &intervals)
{
    sort(intervals.begin(), intervals.end(),
         [](vector< int > &a, vector< int > &b) {
             return a[1] < b[1];
         });
    int count = 1, mark = 0, lim = intervals.size();
    for (int i = 1; i < lim; ++i)
    {
        if (intervals[i][0] >= intervals[mark][1])
        {
            ++count;
            mark = i;
        }
    }
    return lim - count;
}

int main()
{
    vector< vector< int>> shit = {};
    cout << eraseOverlapIntervals(shit);
}