#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 300007
#define mod 998244353
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

inline void add(int &a, int b) {a = (a + b >= mod ? a + b - mod : a + b);}

vector<int> e[N];

int ans, f[N];

// f[u] : at least choose 1 node, anc - des relationship not appear 

void dfs(int u, int fa) {
    f[u] = 1;
    for (auto v : e[u]) if (v != fa) {
        dfs(v, u); add(ans, f[v]);
        f[u] = 1ll * f[u] * (f[v] + 1) % mod;
    }
}

inline void work() {
    ans = 1;
    int n = rd();
    rep(i, 1, n) e[i].clear();
    rep(i, 1, n - 1) {
        int u = rd(), v = rd();
        e[u].eb(v); e[v].eb(u);
    }
    dfs(1, 1); add(ans, f[1]);
    printf("%d\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}