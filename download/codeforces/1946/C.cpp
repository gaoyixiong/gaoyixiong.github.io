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
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 100007

vector<int> e[N];

int c, ans, f[N];

void dfs(int u, int fa) {
    f[u] = 1;
    for (auto v : e[u]) if (v != fa) {dfs(v, u); f[u] += f[v];}
    if (f[u] >= c && u != 1) {++ans; f[u] = 0;}
}

inline void work() {
    int n = rd(), k = rd();
    rep(i, 1, n) e[i].clear();
    rep(i, 1, n - 1) {
        int u = rd(), v = rd();
        e[u].eb(v); e[v].eb(u);
    }

    auto valid = [&](int x) {
        ans = 0; c = x;
        dfs(1, 1); ans -= (f[1] < c);
        return ans >= k;
    };
    
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        valid(mid) ? l = mid : r = mid - 1;
    }
    printf("%d\n", l);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}