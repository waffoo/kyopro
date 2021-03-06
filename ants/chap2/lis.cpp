#include <algorithm>
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, tmp;
    vector<int> arr;
    cin >> n;
    rep (i, n) {
        cin >> tmp;
        arr.pb(tmp);
    }

    vector<int> dp(n, INF);
    rep (i, n)
        *lower_bound(all(dp), arr[i]) = arr[i];

    print(lower_bound(all(dp), INF) - dp.begin());
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