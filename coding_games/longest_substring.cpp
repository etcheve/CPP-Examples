//Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without duplicate characters.
//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        std::unordered_map<char, int> lastIndex;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {

            char c = s[right];

            if (lastIndex.count(c) && lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }

            lastIndex[c] = right;

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};