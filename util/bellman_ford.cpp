#include "bellman_ford.h"

int BellmanFord::solve(int start, int goal) {
    dis = std::vector<int>(n_nodes, INF);
    dis[start] = 0;
    while (true) {
        bool update = false;
        for (auto& e : edges) {
            if (dis[e.from] != INF and dis[e.to] > dis[e.from] + e.cost) {
                dis[e.to] = dis[e.from] + e.cost;
                update = true;
            }
            if (not update) return dis[goal];
        }
    }
}

bool BellmanFord::negLoop() {
    dis = std::vector<int>(n_nodes, 0);
    for (int i = 0; i < n_nodes; i++) {
        for (auto& e : edges) {
            if (dis[e.to] > dis[e.from] + e.cost) {
                dis[e.to] = dis[e.from] + e.cost;
                if (i == n_nodes - 1) return true;
            }
        }
    }
    return false;
}