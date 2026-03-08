// https://leetcode.com/problems/non-overlapping-intervals/description/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
        return a[1] < b[1]; 
    });
        int lastEnd = -500000;
        int inserted = 0;
        for (auto oint : intervals){
            if (oint[0] >= lastEnd){
                ++inserted;
                lastEnd = oint[1];
            }

        }
        int total = intervals.size();
        return total - inserted;
    }
};