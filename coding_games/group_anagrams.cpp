// Group Anagrams
//https://leetcode.com/problems/group-anagrams/description/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> annagrams;
        for (const string& s :  strs){
            vector<int> freq(26,0);
            for (char c : s){
                ++freq[c-'a'];
            }
            string key = generateKey(freq);
            annagrams[key].push_back(s);
        }
        for (auto& [key, group] : annagrams){
            result.push_back(group);
        }
        return result;
    }
    string generateKey(vector<int>& a) {
        string s = "" ;
        for(int i = 0; i < a.size();++i){
            s+=a[i]+',';
        }
        return s;
    }
};