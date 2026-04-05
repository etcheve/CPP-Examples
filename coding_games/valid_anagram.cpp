// https://leetcode.com/problems/valid-anagram/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> letters(30,0);
        for(int i = 0 ; i < s.size(); ++i){
            ++letters[s[i]-'a'];
        }
        for(int i = 0 ; i < t.size(); ++i){
            --letters[t[i]-'a'];
        }
        for (int i = 0 ; i < letters.size(); ++i){
            if (letters[i]!=0){
                return false;
            }
        }
        return true;
    }
};