#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> freq;
        for (auto num : nums){
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto &p : freq) {
            int num = p.first;
            int count = p.second;
            buckets[count].push_back(num);
        }

        vector<int> result;
        for (int f = nums.size(); f >= 1 && result.size() < k; --f) {
            for (int num : buckets[f]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};