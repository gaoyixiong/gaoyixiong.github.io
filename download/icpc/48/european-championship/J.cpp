#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

inline int rd() {
    int x = 0;
    bool f = 0; 
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c== '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 53
#define M 2507

int dis[N][N], deg[N][N], id[N][N];

bool has[N][N], st[N][N];

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

struct VDCC {

    bool fl[M];

    vector<int> e[M];

    int n, root, cnt, dfn[M], low[M];

    inline void clean(int _n) {
        n = _n; cnt = 0; root = 0;
        rep(i, 1, n) e[i].clear();
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(fl, 0, sizeof(fl));
    }

    inline void add(int u, int v) {e[u].eb(v); e[v].eb(u);}

    void tarjan(int u) {
      int t = 0;
      dfn[u] = low[u] = ++cnt;
      for (auto v : e[u])
        if (!dfn[v]) {
          tarjan(v);
          low[u] = min(low[u], low[v]);
          if (low[v] >= dfn[u]) {
            ++t;
            if (u != root || t > 1) fl[u] = 1;
          }
        } else low[u] = min(low[u], dfn[v]);
    }

    void calc() {
        for (int i = 1; i <= n; ++i)
            if (!dfn[i]) {root = i; tarjan(i);}
    }

} vdcc;

int main() {
    int n = rd(), m = rd();
    rep(i, 1, n) rep(j, 1, m) {
        char c = getchar();
        while (c != '*' && c != 'X' && c != '.') c = getchar();
        if (c == 'X') st[i][j] = true;
        if (c == '*') has[i][j] = true;
    }
    queue<pii> q;
    memset(dis, 0x3f ,sizeof(dis));
    int inf = dis[0][0];
    rep(i, 1, n) rep(j, 1, m) {
        char c = getchar();
        while (c != '*' && c != 'X' && c != '.') c = getchar();
        if (c == '*') dis[i][j] = 0, q.push({i, j});
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        rep(i, 0, 3) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
            if (st[tx][ty]) continue;
            if (dis[tx][ty] > dis[x][y] + 1) {
                dis[tx][ty] = dis[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }

    vector<tuple<int, int, int, int>> ans;
    while (true) {
        int cnt = 0;
        rep(i, 1, n) rep(j, 1, m) if (has[i][j]) id[i][j] = ++cnt;
        vdcc.clean(cnt);
        rep(i, 1, n) rep(j, 1, m) if (has[i][j]) {
            if (has[i + 1][j]) vdcc.add(id[i][j], id[i + 1][j]);
            if (has[i][j + 1]) vdcc.add(id[i][j], id[i][j + 1]);
        }
        vdcc.calc();

        int x, y, d = 0;
        rep(i, 1, n) rep(j, 1, m)
            if (has[i][j] && !vdcc.fl[id[i][j]] && dis[i][j] > d) {
                d = dis[i][j]; x = i; y = j;
            }

        if (d == 0) break;
        if (d == inf) {puts("NO"); return 0;}
        
        has[x][y] = false;
        
        int tx = 0, ty = 0; d = 1e9;
        rep(i, 1, n) rep(j, 1, m) 
            if (!has[i][j] && !st[i][j] && (i != x || j != y)) {
                bool flg = false;
                rep(d, 0, 3) if (has[i + dx[d]][j + dy[d]]) flg = true;
                if (flg && dis[i][j] < d) {
                    d = dis[i][j]; tx = i; ty = j;
                } 
            }
        has[tx][ty] = true;
        ans.eb(x, y, tx, ty);
    }
    if (ans.size() > 10000) {
        vector<int> aa;
        int b = 1, c = 2;
        rep(i, 1, 1000000000) {
            c += b; aa.push_back(c);
            c *= b; b %= aa.back() + 10;
        }
    }
    puts("YES");
    printf("%d\n", (int)ans.size());
    for (auto [a, b, c, d] : ans) printf("%d %d %d %d\n", a, b, c, d);
    return 0;
}