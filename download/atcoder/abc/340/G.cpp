#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 200007
#define mod 998244353
#define pb push_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

vector<int> e[N];

int lg[N] = {-1}, tot, dfn[N], dep[N];

int st[18][N], mn[18][N];

int getpre(int u, int v) {return dfn[u] < dfn[v] ? u : v;}

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    st[0][dfn[u] = ++tot] = fa;
    for (auto v : e[u]) if (v != fa) dfs(v, u);
}

int lca(int u, int v) {
    if (u == v) return u;
    if ((u = dfn[u]) > (v = dfn[v])) swap(u, v);
    int k = lg[v - u++];
    return getpre(st[k][u], st[k][v - (1 << k) + 1]);
} 

int col[N], f[N], g[N], ans, tar;

vector<int> son[N], scol[N];

int qmn(int l, int r) {
    int k = lg[r++ - l++ + 1];
    return min(mn[k][l], mn[k][r - (1 << k) + 1]);
}

// f[u] : number of components u is the top node
// g[u] : number of conponents in f[u] that deg[u] = 1

inline void add(int &a, int b) {a = (a + b >= mod ? a + b - mod : a + b);}

void dp(int u) {
    f[u] = 1; g[u] = 0;
    for (auto v : son[u]) {
        dp(v);
        add(g[u], f[v]);
        f[u] = 1ll * f[u] * (f[v] + 1) % mod;
    } 
    if (col[u] == tar) add(ans, f[u]);
    else {
        add(f[u], mod - 1);
        add(ans, (f[u] - g[u] < 0 ? f[u] + mod - g[u] : f[u] - g[u]));
    }
}

void calc(vector<int> &s) {
    if (s.size() == 1) {add(ans, 1); return;}
    sort(all(s), [&](int a, int b){return dfn[a] < dfn[b];});
    per(i, s.size() - 2, 0) s.pb(lca(s[i], s[i + 1]));
    sort(all(s), [&](int a, int b){return dfn[a] < dfn[b];});
    s.erase(unique(all(s)), s.end());
    per(i, s.size() - 2, 0) son[lca(s[i], s[i + 1])].pb(s[i + 1]);

    dp(s.front());
    for (auto x : s) son[x].clear();
}

int main() {
    rep(i, 1, N - 1) lg[i] = lg[i >> 1] + 1;
    int n = rd();
    rep(i, 1, n) scol[col[i] = rd()].pb(i);
    rep(i, 2, n) {int u = rd(), v = rd(); e[u].pb(v); e[v].pb(u);}
    dfs(1, 0);
    rep(i, 1, lg[n]) 
        rep(u, 1, n - (1 << i) + 1) {
            st[i][u] = getpre(st[i - 1][u], st[i - 1][u + (1 << i - 1)]);
            mn[i][u] = min(mn[i - 1][u], mn[i - 1][u + (1 << i - 1)]);
        }
    for (int i = 1; i <= n; ++i) 
        if (!scol[i].empty()) tar = i, calc(scol[i]);
    printf("%d\n", ans);
    return 0;
}