#pragma once

#include <climits>
#include <vector>

struct Edge {
    int from, to, cost;
};

class BellmanFord {
    std::vector<Edge> edges;
    int n_nodes;
    std::vector<int> dis;
    static constexpr int INF = INT_MAX / 2;

public:
    BellmanFord(std::vector<Edge>& es, int V) : edges(es), n_nodes(V) {}

    int solve(int start, int goal);
    bool negLoop();
};