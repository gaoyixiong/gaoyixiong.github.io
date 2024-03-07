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

#define N 200007

ll dis[N];

bool vis[N];

vector<tuple<int, int, int, int, int>> e[N];

int main() {
    int n = rd(), m = rd();
    rep(i, 1, m) {
        int l = rd(), d = rd(), k = rd(), c = rd(), a = rd(), b = rd();
        e[b].eb(a, l, d, k, c);
    }
    memset(dis, -1, sizeof(dis));
    priority_queue<pair<ll, int>> q;
    dis[n] = 5e18;
    q.push({dis[n], n});
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (vis[u]) continue; vis[u] = true;
        for (auto [v, l, d, k, c] : e[u]) {
            if (dis[u] - c < l) continue;
            ll t = l + min(k - 1ll, (dis[u] - c - l) / d) * d;
            if (t > dis[v]) {dis[v] = t; q.push({dis[v], v});}
        }
    }
    rep(u, 1, n - 1) 
        if (dis[u] >= 0) printf("%lld\n", dis[u]);
        else puts("Unreachable");
    return 0;
}