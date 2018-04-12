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
    int cost, to;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V;  // num of nodes
    cin >> V;
    vector<bool> used(V, false);
    int ans = 0, from, to, cost;
    vector<vector<Edge>> adj(V);
    typedef pair<int, int> P;  // first: distance, second: edge num
    pqr<P> q;
    q.push({0, 0});

    while (cin >> from >> to >> cost) {
        adj[from].pb(Edge{cost, to});
        adj[to].pb(Edge{cost, from});
    }

    while (not q.empty()) {
        P p = q.top();
        q.pop();
        if (used[p.second]) continue;

        used[p.second] = true;
        ans += p.first;
        repall (node, adj[p.second])
            q.push({node.cost, node.to});
    }

    print("cost:", ans);

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
