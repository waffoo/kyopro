// p73 expedition
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < static_cast<int>(b); i++)
#define FORR(i, a, b) for (int i = (a); i > static_cast<int>(b); i--)
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

    int n, l, p, ta, tb;
    int gas[1000000] = {0};
    pq<int> q;

    cin >> n >> l >> p;
    q.push(p);
    rep (i, n) {
        cin >> ta >> tb;
        gas[ta] = tb;
    }

    int cnt = -1;
    for (int pos = 0, tank = 0; pos < l; cnt++) {
        tank = q.top(), q.pop();
        while (tank > 0) {
            tank--, pos++;
            if (gas[pos] > 0) q.push(gas[pos]);
        }
        if (q.empty()) {
            print(-1);
            return 0;
        }
    }
    print(cnt);

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
