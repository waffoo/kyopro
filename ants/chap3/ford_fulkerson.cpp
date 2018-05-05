#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < static_cast<int>(b); i++)
#define rep(i, n) FOR (i, 0, n)
#define repall(i, arr) for (auto& i : (arr))
#define pb push_back
template <typename Arg>
void print(const Arg arg);
const int INF = INT_MAX / 2;

struct Edge {
    int to, cap, rev;
};

constexpr int MAX_V = 10000;
vector<Edge> net[MAX_V];
bool used[MAX_V];

int dfs(int v, int t, int f) {
    if (v == t) return f;
    used[v] = true;
    repall (e, net[v]) {
        if (not used[e.to] and e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                net[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n_edges, st, gl;
    cin >> n_edges >> st >> gl;

    int from, to, cap;
    rep (i, n_edges) {
        cin >> from >> to >> cap;
        net[from].pb(Edge{to, cap, int(net[to].size())});
        net[to].pb(Edge{from, 0, int(net[from].size() - 1)});
    }

    int flow = 0;
    while (true) {
        memset(used, 0, sizeof(used));
        int f = dfs(st, gl, INF);
        if (f == 0) break;
        flow += f;
    }

    print(flow);

    return 0;
}

//---------------------------------------------
template <typename Arg>
void print(const Arg arg) {
    cout << arg << '\n';
}