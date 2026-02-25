// FUll ai answer 
// https://leetcode.com/problems/word-ladder-ii/
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (!dict.count(endWord)) 
            return result;

        // BFS
        unordered_map<string, vector<string>> parents; // reverse graph
        unordered_set<string> currentLevel{beginWord};
        unordered_set<string> visited;
        bool found = false;

        while (!currentLevel.empty() && !found) {
            unordered_set<string> nextLevel;

            for (auto& word : currentLevel)
                visited.insert(word);

            for (auto& word : currentLevel) {
                string temp = word;

                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;

                        if (!dict.count(temp) || visited.count(temp))
                            continue;

                        if (temp == endWord)
                            found = true;

                        nextLevel.insert(temp);
                        parents[temp].push_back(word);
                    }

                    temp[i] = original;
                }
            }

            currentLevel = nextLevel;
        }

        if (!found)
            return result;

        // DFS backtracking
        vector<string> path{endWord};
        backtrack(endWord, beginWord, parents, path, result);

        return result;
    }

private:
    void backtrack(string word, string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path,
                   vector<vector<string>>& result) {
        
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }

        for (auto& parent : parents[word]) {
            path.push_back(parent);
            backtrack(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};