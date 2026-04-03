// Graph header file
#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <utility>

class Graph {
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void dijkstra(int src);
};

#endif // GRAPH_H
