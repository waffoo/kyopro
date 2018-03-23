#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < static_cast<int>(b); i++)
#define FORR(i, a, b) for (int i = (a); i >= static_cast<int>(b); i--)
#define rep(i, n) FOR (i, 0, n)
#define repall(i, arr) for (auto& i : (arr))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dump(x) cerr << #x << " = " << (x) << '\n'
template <typename T>
void print(const vector<vector<T>> matrix);
template <typename T>
void print(const vector<T> vec);
template <typename Arg>
void print(const Arg arg);
template <typename Head, typename... Args>
void print(const Head head, const Args... args);
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using pqr = priority_queue<T, vector<T>, greater<T>>;
const int INF = INT_MAX / 2;

struct Edge {
    int to, cost;
};

int node(char c) { return c - 'A'; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, cost;
    char start, goal, from, to;
    cin >> V >> start >> goal;
    vector<vector<Edge>> adj(V);  // adjacency list
    vector<int> dis(V, INF);
    typedef pair<int, int> P;  // first: distance; second: edge num

    pqr<P> q;
    dis[node(start)] = 0;
    q.push({0, node(start)});

    while (cin >> from >> to >> cost) {
        adj[node(from)].pb({node(to), cost});
        adj[node(to)].pb({node(from), cost});
    }

    while (not q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if (dis[v] < p.first) continue;
        repall (e, adj[v]) {
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                q.push({dis[e.to], e.to});
            }
        }
    }

    print(dis[node(goal)]);

    return 0;
}

//---------------------------------------------
template <typename T>
void print(const vector<vector<T>> matrix) {
    repall (vec, matrix)
        print(vec);
}
template <typename T>
void print(const vector<T> vec) {
    repall (i, vec)
        cout << i << ' ';
    cout << '\n';
}
template <typename Arg>
void print(const Arg arg) {
    cout << arg << '\n';
}
template <typename Head, typename... Args>
void print(const Head head, const Args... args) {
    cout << head << " ";
    print(args...);
}
