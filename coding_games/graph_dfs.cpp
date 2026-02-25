// https://leetcode.com/problems/evaluate-division/
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;    
class Solution {
public:
    
    unordered_map<string, vector<pair<string,double>>> graph;
    
    double findCost(string a, 
                    string b,
                    unordered_set<string>& visited,
                    double acc ){
        if (a == b) return acc;
        visited.insert(a);

        for (auto& [next, w] : graph[a]) {
            if (visited.count(next)) continue;
            double res = findCost(next, b, visited, acc * w);
            if (res != -1.0) return res;
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    vector<double> answers;
    for(int i = 0; i < equations.size(); ++i){
        string key = equations[i][0];
        string key2 = equations[i][1];
        double value = values[i];

        graph[key].push_back({key2, value});
        graph[key2].push_back({key, 1/value});

    }
    for (auto q : queries){
        auto it1 = graph.find(q[0]);
        if (it1 == graph.end()){
            answers.push_back(-1.0);
            continue;
        }
        auto it2 = graph.find(q[0]);
        if (it2 == graph.end()){
            answers.push_back(-1.0);
            continue;
        }

        if (q[0] == q[1]){
            answers.push_back(1.0);
            continue;
        }
        std::unordered_set<string> visited;  
        answers.push_back(findCost(q[0] ,q[1], visited, 1.0));    
    }     
    return answers;
    }
};