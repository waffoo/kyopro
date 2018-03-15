// p37 maze
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
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
const int INF = INT_MAX / 2;

int n, m;
vector<vector<char>> field;
vector<vector<int>> dis;
using Pos = pair<int, int>;
queue<Pos> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool in(int x, int y) { return 0 <= x and x < n and 0 <= y and y < m; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    char c;
    rep(i, n) {
        vector<char> row;
        rep(j, m) {
            cin >> c;
            if (c == 'S') q.push(Pos(i, j));
            row.pb(c);
        }
        field.pb(row);
        dis.pb(vector<int>(m, INF));
    }

    Pos start = q.front();
    dis[start.first][start.second] = 0;

    while (q.size()) {
        Pos now = q.front();
        q.pop();

        rep(i, 4) {
            int x = now.first + dx[i], y = now.second + dy[i];
            if (in(x, y) and field[x][y] != '#' and dis[x][y] == INF) {
                q.push(Pos(x, y));
                dis[x][y] = dis[now.first][now.second] + 1;
                if (field[x][y] == 'G') {
                    print(dis[x][y]);
                    break;
                }
            }
        }
    }
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
