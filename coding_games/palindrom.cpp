// https://leetcode.com/problems/longest-palindromic-substring/description/

//Given a string s, return the longest palindromic substring in s.

#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int maxL = 1;
        int index = 0;

        for (int i = 0; i < s.size(); ++i) {
            // Odd length palindrome
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > maxL) {
                    maxL = right - left + 1;
                    index = left;
                }
                --left;
                ++right;
            }

            // Even length palindrome
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > maxL) {
                    maxL = right - left + 1;
                    index = left;
                }
                --left;
                ++right;
            }
        }

        return s.substr(index, maxL);
    }
};