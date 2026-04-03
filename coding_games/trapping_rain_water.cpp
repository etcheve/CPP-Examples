// https://leetcode.com/problems/trapping-rain-water/description/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxHeightL(n,0);
        vector<int> maxHeightR(n,0);
        maxHeightL[0]=height[0];
        for(int i = 1; i < n; ++i){
            maxHeightL[i] = max(maxHeightL[i-1],height[i]);
        }
        maxHeightR[n-1]=height[n-1];
       for(int i = n-2; i >= 0; --i){
            maxHeightR[i]= max(maxHeightR[i+1],height[i]);
        }
        int result = 0;
        for(int i = 1; i < n; ++i){
            int trapped = min (maxHeightL[i],maxHeightR[i])-height[i];
            
            result += trapped > 0 ? trapped : 0;
        }
        return result;
    }
};