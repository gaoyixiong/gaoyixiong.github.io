#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

inline ll rd() {
    ll x = 0;
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

#define N 100007

const ll inf = 4000000000000000000ll;

bool vis[N];

vector<int> e[N];

ll dis[N], l[N], s[N];

ll exgcd(ll &x, ll &y, ll a, ll b) {
    if (!b) {x = 1ll; y = 0ll; return a;}
    ll g = exgcd(x, y, b, a % b);
    ll t = x; x = y; y = t - (a / b) * y;
    return g;
}

inline void work() {
    int n = rd(), m = rd();
    ll H = rd();
    rep(i, 1, n) dis[i] = inf, vis[i] = false, e[i].clear();
    rep(i, 1, n) l[i] = rd();
    rep(i, 1, n) s[i] = rd();
    rep(i, 1, m) {int u = rd(), v = rd(); e[u].eb(v); e[v].eb(u);}
    dis[1] = 1;
    priority_queue<pli,vector<pli>, greater<pli>> q;
    q.push({1, 1});
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (vis[u]) continue; vis[u] = true;
        ll lu = (l[u] + (dis[u] - 1) % H * s[u]) % H;
        for (auto v : e[u]) {
            ll lv = (l[v] + (dis[u] - 1) % H * s[v]) % H;
            ll b = (lv + H - lu) % H;
            ll a = (s[u] + H - s[v]) % H;
            // find minimum x satisfies ax = b (mod H)
            // ax + Hy = b;
            ll x, y;
            ll g = exgcd(x, y, a, H);
            if (b % g != 0) continue;
            ll dx = H / g;
            ll t = (x * b / g % dx + dx) % dx + 1;
            if (dis[v] > dis[u] + t) {
                dis[v] = dis[u] + t;
                q.push({dis[v], v});
            }
        }
    }
    printf("%lld\n", dis[n] >= inf ? -1 : dis[n] - 1);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}