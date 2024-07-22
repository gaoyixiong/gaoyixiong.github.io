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

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 5007

int w[N], id[N];

vector<int> e[N];

ll ans[N], f[N][N];

int main() {
    int n = rd(), m = rd();
    rep(i, 1, m) {
        int u = rd(), v = rd();
        e[u].eb(v); e[v].eb(u);
    }
    rep(i, 1, n) w[i] = rd(), id[i] = i;
    sort(id + 1, id + 1 + n, [&](int x, int y){return w[x] < w[y];});
    for (int i = 1; i <= n; ++i) {
        int u = id[i];
        ans[u] = f[u][w[u] - 1] + 1;
        for (auto v : e[u]) if (w[v] > w[u]) {
            per(s, N - 1, w[u]) f[v][s] = max(f[v][s], f[v][s - w[u]] + ans[u]);
        }
    }
    ll res = 0;
    rep(i, 1, n) res += rd() * ans[i];
    printf("%lld\n", res);
    return 0;
}