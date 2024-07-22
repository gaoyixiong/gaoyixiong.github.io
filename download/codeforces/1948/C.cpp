#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 200007

bool mp[2][N], vis[N << 1];

vector<int> e[N << 1];

queue<int> q;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        rep(i, 0, 1) rep(j, 1, n) {
            char c; cin >> c;
            while (c != '<' && c != '>') cin >> c;
            mp[i][j] = (c == '>');
        }
        auto valid = [&](int x, int y) {
            return (x >= 0 && x <= 1 && y >= 1 && y <= n);
        };
        rep(i, 1, (n << 1)) vis[i] = false, e[i].clear();
        rep(i, 0, 1) rep(j, 1, n) {
            int u = i * n + j;
            rep(d, 0, 3) {
                int tx = i + dx[d];
                int ty = j + dy[d];
                if (!valid(tx, ty)) continue;
                mp[tx][ty] ? ++ty : --ty;
                int v = tx * n + ty;
                e[u].emplace_back(v);
            }
        }
        vis[1] = true; q.push(1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : e[u]) 
                if (!vis[v]) {vis[v] = true; q.push(v);}
        }
        puts(vis[n << 1] ? "YES" : "NO");
    }
    return 0;
}