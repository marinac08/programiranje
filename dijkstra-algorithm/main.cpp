#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int source, vector<vector<pii>>& adj, int V) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<vector<pii>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int s;
    cin >> s;

    dijkstra(s, adj, V);

    return 0;
}
