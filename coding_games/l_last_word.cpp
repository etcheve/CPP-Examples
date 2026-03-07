// https://leetcode.com/problems/length-of-last-word/submissions/1939861318/

// Given a string s consisting of words and spaces, return the length of the last word in the string.
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int sl = s.size()-1;

        while (sl >=0 && s[sl] == ' ' ){
            --sl;
        }
        int count = 0;
        while (sl >=0 && s[sl]!=' ' ){
            --sl;
            ++count;
        }
        return count;
        
    }
};