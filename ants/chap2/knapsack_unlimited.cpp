// p58 unlimited-knapsack memory-efficient dp
#include <climits>
#include <iostream>
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
const int INF = INT_MAX / 2;

struct Obj {
    int weight, value;
    Obj(int w, int v) : weight(w), value(v) {}
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, w, v, lim;
    vector<Obj> goods{Obj(0, 0)};
    cin >> n;
    rep (i, n) {
        cin >> w >> v;
        goods.pb(Obj(w, v));
    }
    cin >> lim;
    vector<int> dp(lim + 1, 0);

    FOR (i, 1, n + 1)
        FOR (j, goods[i].weight, lim + 1)
            dp[j] = max(dp[j], dp[j - goods[i].weight] + goods[i].value);

    print(dp[lim]);
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