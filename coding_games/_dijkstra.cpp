
#include <vector>
#include <queue>
using namespace std;  
// Find shortest path from node 0 to n-1 with positive weights.  

int dijkstra(int n, vector<vector<pair<int,int>>>& adj) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<>> pq;

    dist[0] = 0;
    pq.push({0,0}); // {distance, node}

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v,w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[n-1];
}