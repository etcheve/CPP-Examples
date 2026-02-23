#include <set>
/////////////////////////// *********************** ////////////////////
// std::set 
std::set<int> s;                     // ascending (default)
std::set<int, std::greater<int>> s2; // descending



// Custom comparator 
struct Comp {
    bool operator()(int a, int b) const {
        return a % 10 < b % 10;  // sort by last digit
    }
};

std::set<int, Comp> s;

s.insert(5);

auto it = s.find(5);
if (it != s.end()) { /* found */ }

s.erase(5);          // by value
s.erase(s.begin());  // by iterator


/////////////////////////// *********************** ////////////////////
// st::unordered_map
#include <unordered_map>
std::unordered_map<std::string,int> mp;

mp["a"] = 10;      // insert/update
mp.count("a");     // 1 if exists
mp.find("a");      // iterator
mp.erase("a");

/////////////////////////// *********************** ////////////////////
// st::vector
#include <algorithm>

std::sort(v.begin(), v.end()); // ascending
std::sort(v.begin(), v.end(), std::greater<int>());

std::sort(v.begin(), v.end(),
    [](int a, int b) {
        return a % 10 < b % 10;
    });

std::sort(v.begin(), v.end(),
    [](auto &a, auto &b) {
        return a.second < b.second;
    });

std::min(a,b)
std::max(a,b)
std::swap(a,b)
std::abs(x)
std::accumulate(v.begin(), v.end(), 0)
std::count(v.begin(), v.end(), x)
std::lower_bound(...)
std::upper_bound(...)
std::greater<int>()
std::less<int>()    

#include <limits>
int INF = std::numeric_limits<int>::max();
const int INF = 1e9;   // safer for addition 


| Problem type                     | Tool             |
| -------------------------------- | ---------------- |
| Shortest path unweighted         | BFS              |
| Shortest path weighted           | Dijkstra         |
| Bounded edges                    | Bellman-Ford     |
| All combinations                 | DFS/backtracking |
| Repeated overlapping subproblems | DP               |
| Local best choice works          | Greedy           |
