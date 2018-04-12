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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V;  // num of nodes
    cin >> V;
    vector<vector<int>> cost(V, vector<int>(V, INF));
    vector<int> mincost(V, INF);
    vector<bool> used(V, false);
    mincost[0] = 0;
    int ans = 0;
    int from, to, weight;

    while (cin >> from >> to >> weight)
        cost[from][to] = cost[to][from] = weight;

    while (true) {
        int near = -1;
        rep (i, V)
            if (not used[i] and (near == -1 or mincost[i] < mincost[near]))
                near = i;

        if (near == -1) break;
        used[near] = true;
        ans += mincost[near];

        rep (i, V)
            mincost[i] = min(mincost[i], cost[near][i]);
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
