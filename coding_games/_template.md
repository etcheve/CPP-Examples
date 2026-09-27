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

        std::vector<std::vector<int>> poss(m+1, std::vector<int>(n+1, 0));

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


stack<int> st;

st.push(3);     // add to top
st.pop();       // remove top (returns void!)
st.top();       // peek at top without removing
st.empty();     // true if empty
st.size();      // number of elements

#include <algorithm>   // min, max, swap, count, lower_bound, upper_bound, greater, less
#include <cmath>       // abs (for floats)
#include <cstdlib>     // abs (for ints)
#include <numeric>     // accumulate

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


push — ordered containers where position matters
cppstack.push(x)       // top
queue.push(x)       // back
vector.push_back(x) // back
insert — containers that manage their own ordering
cppset.insert(x)
map.insert({key, val})
unordered_set.insert(x)
unordered_map.insert({key, val})


| Problem type                     | Tool             |
| -------------------------------- | ---------------- |
| Shortest path unweighted         | BFS              |
| Shortest path weighted           | Dijkstra         |
| Bounded edges                    | Bellman-Ford     |
| All combinations                 | DFS/backtracking |
| Repeated overlapping subproblems | DP               |
| Local best choice works          | Greedy           |



#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;

    dq.push_back(10);   // [10]
    dq.push_back(20);   // [10, 20]
    dq.push_front(5);   // [5, 10, 20]

    std::cout << dq.front() << "\n"; // 5
    std::cout << dq.back()  << "\n"; // 20
    std::cout << dq[1]      << "\n"; // 10

    dq.pop_front(); // [10, 20]
    dq.pop_back();  // [10]

    std::cout << dq.size()  << "\n"; // 1
    std::cout << dq.empty() << "\n"; // 0 (false)
}