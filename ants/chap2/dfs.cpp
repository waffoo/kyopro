// p35 Lake Counting
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)
#define pb push_back
#define dump(x) cerr << #x << " = " << (x) << '\n'
template <typename Arg>
void print(Arg arg);
template <typename Head, typename... Args>
void print(Head head, Args... args);

int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;
vector<vector<bool>> field;

bool in(int i, int j) { return 0 <= i and i < n and 0 <= j and j < m; }

void dfs(int i, int j) {
    field[i][j] = false;
    rep(k, 8) {
        int x = i + di[k], y = j + dj[k];
        if (in(x, y) and field[x][y]) {
            dfs(x, y);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    char c;
    rep(i, n) {
        vector<bool> row;
        rep(j, m) {
            cin >> c;
            row.pb(c == 'w');
        }
        field.pb(row);
    }

    int cnt = 0;
    rep(i, n) {
        rep(j, m) {
            if (field[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    print(cnt);
}

//---------------------------------------------
template <typename Arg>
void print(Arg arg) {
    cout << arg << '\n';
}

template <typename Head, typename... Args>
void print(Head head, Args... args) {
    cout << head << " ";
    print(args...);
}
