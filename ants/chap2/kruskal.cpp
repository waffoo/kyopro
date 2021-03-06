#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include "../../util/union_find.h"
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

typedef pair<int, pair<int, int>> Edge;  // dis, (node1, node1)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, from, to, cost, ans = 0;
    cin >> V;
    vector<Edge> edges;
    while (cin >> from >> to >> cost) edges.pb({cost, {from, to}});
    sort(all(edges));

    UnionFind uf(V);
    repall (e, edges) {
        auto ends = e.second;
        if (not uf.isFamily(ends.first, ends.second)) {
            uf.unite(ends.first, ends.second);
            ans += e.first;
        }
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
