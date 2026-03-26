// https://leetcode.com/problems/daily-temperatures/description/

#include <vector>
#include <stack>
using namespace std;    
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<pair<int,int>> myStack;
        for (int i = 0; i < n;++i){
             
            while (!myStack.empty() && 
             myStack.top().first < temperatures[i]) {
                auto pair = myStack.top();
                result[pair.second]=i-pair.second;
                myStack.pop();

          }
            myStack.push({temperatures[i],i});
        }
        return result;
    }
};