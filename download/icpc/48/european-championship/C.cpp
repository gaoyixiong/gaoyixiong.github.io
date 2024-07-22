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

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

int n, sz[N];

vector<int> e[N], center;

void dfs1(int u, int fa) {
    int mxs = 0;
    sz[u] = 1;
    for (auto v : e[u]) 
        if (v != fa) {
            dfs1(v, u);
            sz[u] += sz[v];
            mxs = max(mxs, sz[v]);
        }
    mxs = max(mxs, n - sz[u]);
    if (mxs * 2 <= n) center.eb(u);
}

bool dfs(int u, int fa) {
    sz[u] = 1;
    for (auto v : e[u]) 
        if (v != fa) {
            if (!dfs(v, u)) return false;
            sz[u] += sz[v];
        }
    vector<int> ws;
    for (auto v : e[u]) if (v != fa) ws.eb(sz[v]);
    sort(all(ws));
    int nw = 1;
    for (auto w : ws) 
        if (nw >= w) nw += w;
        else return false;
    return true;
}

int main() {
    n = rd();
    rep(i, 1, n - 1) {
        int u = rd(), v = rd();
        e[u].eb(v); e[v].eb(u);
    }
    dfs1(1, 1);
    for (auto u : center) if (dfs(u, u)) {puts("YES"); return 0;}
    puts("NO");
    return 0;
}