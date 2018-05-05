// p95 bellman-ford
#include "../../util/bellman_ford.h"
#include <bits/stdc++.h>
using namespace std;

template <typename Arg>
void print(const Arg arg);
#define pb push_back

int node(char c) { return c - 'A'; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<Edge> edges;
    char start, goal, from, to;
    int cost;
    cin >> start >> goal;

    while (cin >> from >> to >> cost) {
        edges.pb({node(from), node(to), cost});
        edges.pb({node(to), node(from), cost});
    }

    BellmanFord bellman(edges, 10);

    print(bellman.solve(node(start), node(goal)));
    cout << boolalpha << bellman.negLoop() << endl;

    return 0;
}

//---------------------------------------------
template <typename Arg>
void print(const Arg arg) {
    cout << arg << '\n';
}