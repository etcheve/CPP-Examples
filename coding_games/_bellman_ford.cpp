// Cheapest path from 0 to n-1 with at most K edges.
#include <vector>   
using namespace std;

int bellmanFord(int n,
                vector<vector<int>>& edges,
                int K) {

    const int INF = 1e9;
    vector<int> dist(n, INF);
    dist[0] = 0;

    for (int i = 0; i <= K; ++i) {
        vector<int> next = dist;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] == INF) continue;

            next[v] = min(next[v], dist[u] + w);
        }

        dist = next;
    }

    return dist[n-1] == INF ? -1 : dist[n-1];
}