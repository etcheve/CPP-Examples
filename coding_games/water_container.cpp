// https://leetcode.com/problems/container-with-most-water/description/
/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int hightl = 0;
        int hightr =0;
        int maxArea = 0;
        while (left< right) {
            int h = std::min(height[left], height[right]);
            int w = right - left;
        maxArea = std::max(maxArea, h * w);

        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }
        return maxArea;
    }
};