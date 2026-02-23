// Given an unweighted graph, find shortest distance from node 0 to node n-1.
#include <vector>
#include <queue>
using namespace std;

int shortestPath(int n, vector<vector<int>>& adj) {
    vector<int> dist(n, -1);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[n-1];
}