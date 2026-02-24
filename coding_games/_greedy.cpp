// Activity selection (max non-overlapping intervals).
#include <vector>
#include <algorithm>
using namespace std;


int maxActivities(vector<pair<int,int>>& v) {
    sort(v.begin(), v.end(),
         [](auto &a, auto &b) {
             return a.second < b.second;
         });

    int count = 0;
    int lastEnd = -1;

    for (auto &[start,end] : v) {
        if (start >= lastEnd) {
            count++;
            lastEnd = end;
        }
    }

    return count;
}