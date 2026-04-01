//https://leetcode.com/problems/largest-rectangle-in-histogram/description/
#include <vector>
#include <stack>        
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>  myStack; // stack contains a pair of height, index
        int maxArea = 0;
        for (int i = 0 ; i < heights.size(); ++i){
            if (myStack.empty())   {
                myStack.push({heights[i],i});
                continue;
            } 
            if (myStack.top().first  < heights[i]){
                myStack.push({heights[i],i});
                continue;
            }
            int indexLast=i;
            while (!myStack.empty() && 
                myStack.top().first > heights[i]){
                indexLast = myStack.top().second;
                int area = myStack.top().first * (i - indexLast);
                maxArea = max(maxArea, area);
                myStack.pop();   
            }
            myStack.push({heights[i],indexLast});

        }
        while (!myStack.empty()) {
            auto pair = myStack.top();
            myStack.pop();
            int area = pair.first * (heights.size()  - pair.second);
            maxArea = std::max(maxArea, area);
        }
        return maxArea;
    }
};