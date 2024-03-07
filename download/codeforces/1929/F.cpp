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

#define N 500007
#define mod 998244353
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int ifac[N], lc[N], rc[N], val[N];

inline int fpow(int x, int t = mod - 2) {
    int res = 1;
    for (; t; t >>= 1, x = 1ll * x * x % mod)
        if (t & 1) res = 1ll * res * x % mod;
    return res;
}

inline int C(int n, int m) {
    int ans = ifac[m];
    per(i, n + m - 1, n) ans = 1ll * ans * i % mod;
    return ans;
}

vector<int> s;

void dfs(int u) {
    if (lc[u] > 0) dfs(lc[u]);
    s.eb(val[u]);
    if (rc[u] > 0) dfs(rc[u]);
}

inline void work() {
    int n = rd(), c = rd();
    rep(i, 1, n) lc[i] = rd(), rc[i] = rd(), val[i] = rd();
    s.clear(); s.eb(1); dfs(1); s.eb(c);
    int L = 1, cnt = 0, ans = 1;
    for (auto x : s) {
        if (x == -1) ++cnt;
        else {
            if (cnt) ans = 1ll * ans * C(x - L + 1, cnt) % mod;
            cnt = 0; L = x;
        }
    }
    printf("%d\n", ans);
}

int main() {
    ifac[0] = ifac[1] = 1;
    rep(i, 2, N - 1) ifac[i] = 1ll * i * ifac[i - 1] % mod;
    ifac[N - 1] = fpow(ifac[N - 1]);
    per(i, N - 2, 1) ifac[i] = 1ll * (i + 1) * ifac[i + 1] % mod;
    per(t, rd(), 1) work();
    return 0;
}