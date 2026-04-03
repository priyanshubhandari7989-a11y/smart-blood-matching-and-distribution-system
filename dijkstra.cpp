// Implementation of Dijkstra's Algorithm
#include <iostream>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void dijkstra(int src);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::dijkstra(int src) {
    vector<int> dist(V, numeric_limits<int>::max());
    dist[src] = 0;
    vector<bool> sptSet(V, false);

    for (int count = 0; count < V - 1; count++) {
        int min_index;
        int min_value = numeric_limits<int>::max();
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && dist[v] <= min_value) {
                min_value = dist[v];
                min_index = v;
            }
        }
        sptSet[min_index] = true;
        for (const auto& pair : adj[min_index]) {
            int v = pair.first;
            int weight = pair.second;
            if (!sptSet[v] && dist[min_index] != numeric_limits<int>::max() && dist[min_index] + weight < dist[v]) {
                dist[v] = dist[min_index] + weight;
            }
        }
    }

    cout << "Vertex Distance from Source:\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}
