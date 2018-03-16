// p52 knapsack-dp
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < static_cast<int>(b); i++)
#define rep(i, n) FOR(i, 0, n)
#define repall(i, arr) for (auto& i : (arr))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dump(x) cerr << #x << " = " << (x) << '\n'
template <typename Arg>
void print(Arg arg);
template <typename Head, typename... Args>
void print(Head head, Args... args);
const int INF = INT_MAX / 2;

struct Obj {
    Obj(int w, int v) : weight(w), value(v) {}
    int weight;
    int value;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, lim, w, v;
    vector<Obj> goods = {Obj(0, 0)};
    vector<vector<int>> dp;
    cin >> n;
    rep(i, n) {
        cin >> w >> v;
        goods.pb(Obj(w, v));
    }
    cin >> lim;
    rep(i, n + 1) dp.pb(vector<int>(lim + 1, 7));

    repall(row, dp) row[0] = 0;
    repall(i, dp[0]) i = 0;

    FOR(i, 1, n + 1) {
        FOR(j, 1, lim + 1) {
            if (goods[i].weight > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j],
                               dp[i - 1][j - goods[i].weight] + goods[i].value);
        }
    }

    print(dp[n][lim]);
}

//---------------------------------------------
template <typename Arg>
void print(Arg arg) {
    cout << arg << '\n';
}

template <typename Head, typename... Args>
void print(Head head, Args... args) {
    cout << head << ' ';
    print(args...);
}
