// Generate all subsets of array.

#include <vector>
using namespace std;
void dfs(int i,
         vector<int>& nums,
         vector<int>& cur,
         vector<vector<int>>& ans) {

    if (i == nums.size()) {
        ans.push_back(cur);
        return;
    }

    // not take
    dfs(i+1, nums, cur, ans);

    // take
    cur.push_back(nums[i]);
    dfs(i+1, nums, cur, ans);
    cur.pop_back();
}


int fib(int n) {
    if (n <= 1) return n;

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}