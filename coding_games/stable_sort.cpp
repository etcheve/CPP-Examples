// Order a list of words appearing in a file by number of 
// letters but maintain original order ("stable sorting") of words with same length
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> words = {
        "apple", "is", "a", "fruit", "pie", "to", "eat"
    };

    std::stable_sort(words.begin(), words.end(),
        [](const string& a, const string& b) {
            return a.size() < b.size();
        });

    for (const auto& w : words)
        cout << w << " ";
}