// p85 food-chain solved by union-find
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

int n;
int index(int num, char type) { return n * (type - 'A') + num; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k, type, x, y, ans = 0;
    cin >> n >> k;

    UnionFind uf(n * 3);
    rep (i, k) {
        cin >> type >> x >> y;
        if (x < 1 or x > n or y < 1 or y > n) {
            ans++;
            continue;
        }
        switch (type) {
            case 1:
                if (uf.isFamily(index(x, 'A'), index(y, 'B')) or
                    uf.isFamily(index(x, 'A'), index(y, 'C'))) {
                    ans++;
                    continue;
                }
                uf.unite(index(x, 'A'), index(y, 'A'));
                uf.unite(index(x, 'B'), index(y, 'B'));
                uf.unite(index(x, 'C'), index(y, 'C'));
                break;
            case 2:
                if (uf.isFamily(index(x, 'A'), index(y, 'A')) or
                    uf.isFamily(index(x, 'A'), index(y, 'C'))) {
                    ans++;
                    continue;
                }
                uf.unite(index(x, 'A'), index(y, 'B'));
                uf.unite(index(x, 'B'), index(y, 'C'));
                uf.unite(index(x, 'C'), index(y, 'A'));
                break;
            default:
                throw range_error("invalid type id");
        }
    }

    print(ans);

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
