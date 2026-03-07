//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <string>
using namespace std;    

class Solution {
public:
    int strStr(string haystack, string needle) {
    return haystack.find(needle);
    }
};