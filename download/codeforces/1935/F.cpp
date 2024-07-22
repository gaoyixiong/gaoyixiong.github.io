#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

int tot, dfn[N], L[N], R[N], mx[N][18], mn[N][18], lg2[N];

vector<int> e[N];

void dfs1(int u, int fa) {
    L[u] = dfn[u] = ++tot;
    mn[tot][0] = mx[tot][0] = u;
    for (auto v : e[u]) if (v != fa) dfs1(v, u);
    R[u] = tot;
}

inline int qmx(int l, int r) {
    if (l > r) return 0;
    int t = lg2[r - l + 1];
    return max(mx[l][t], mx[r - (1 << t) + 1][t]);
}

inline int qmn(int l, int r) {
    if (l > r) return 1e9;
    int t = lg2[r - l + 1];
    return min(mn[l][t], mn[r - (1 << t) + 1][t]);
}

int n, cst[N];

vector<pii> ans[N];

int f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void dfs2(int u, int fa) {

    vector<pii> edg;
    vector<tii> seg;
    if (u != 1) {
        f[1] = 1;
        if (L[u] != 1) seg.eb(1, L[u] - 1, 1);
        if (R[u] != n) seg.eb(R[u] + 1, n, 1); 
        int b = max(qmx(1, L[u] - 1), qmx(R[u] + 1, n));
        int s = min(qmn(1, L[u] - 1), qmn(R[u] + 1, n));
        if (s != 1 && s - 1 != u) edg.eb(s - 1, s);
        if (b != n && b + 1 != u) edg.eb(b, b + 1);
    }
    for (auto v : e[u]) if (v != fa) {
        f[v] = v;
        seg.eb(L[v], R[v], v);
        int b = qmx(L[v], R[v]), s = qmn(L[v], R[v]);
        if (s != 1 && s - 1 != u) edg.eb(s - 1, s);
        if (b != n && b + 1 != u) edg.eb(b, b + 1);
    }
    sort(all(seg));
    auto check = [&](int w, int a, int b) {
        int repa = get<2>(*--lower_bound(all(seg), make_tuple(dfn[a], n + 1, n + 1)));
        int repb = get<2>(*--lower_bound(all(seg), make_tuple(dfn[b], n + 1, n + 1)));
        if (find(repa) != find(repb)) {f[find(repa)] = find(repb); cst[u] += w; ans[u].eb(a, b);} 
    };

    for (auto [a, b] : edg) check(1, a, b);
    if (u != 1 && u != n) check(2, u - 1, u + 1);

    for (auto v : e[u]) if (v != fa) dfs2(v, u);
}

inline void work() {
    n = rd();
    rep(i, 1, n) cst[i] = 0, ans[i].clear(), e[i].clear();
    rep(i, 1, n - 1) {
        int u = rd(), v = rd();
        e[u].eb(v); e[v].eb(u);
    }
    tot = 0; 
    dfs1(1, 1);
    rep(t, 1, lg2[n]) 
        rep(l, 1, n - (1 << t) + 1) {
            mx[l][t] = max(mx[l][t - 1], mx[l + (1 << (t - 1))][t - 1]);
            mn[l][t] = min(mn[l][t - 1], mn[l + (1 << (t - 1))][t - 1]);
        } 
    dfs2(1, 1);
    rep(i, 1, n) {
        printf("%d %d\n", cst[i], (int)ans[i].size());
        for (auto [u, v] : ans[i]) printf("%d %d\n", u, v);
    }
}

int main() {
    for (int t = 0; (1 << t) < N; ++t) lg2[(1 << t)] = t;
    rep(i, 1, N - 1) if (!lg2[i]) lg2[i] = lg2[i - 1];
    per(t, rd(), 1) work();
    return 0;
}