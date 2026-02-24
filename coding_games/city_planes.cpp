//https://leetcode.com/problems/cheapest-flights-within-k-stops/
#include <vector>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[src] = 0;

        // allow up to k+1 edges
        for (int i = 0; i <= k; ++i) {
            vector<int> next = dist;  // copy — critical
            for (auto &f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] == INF) continue;
                next[v] = min(next[v], dist[u] + w);
            }
            dist = next;
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};