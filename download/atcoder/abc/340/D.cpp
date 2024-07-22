#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, int> pii;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

ll dis[N];

bool vis[N];

vector<pii> e[N];

priority_queue<pii, vector<pii>, greater<pii>> q;

int main() {
    int n = rd();
    rep(i, 1, n - 1) {
        int a = rd(), b = rd(), x = rd();
        e[i].eb(i + 1, a);
        e[i].eb(x, b);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (vis[u]) continue; vis[u] = true;
        for (auto [v, w] : e[u]) 
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
    }
    printf("%lld\n", dis[n]);
    return 0;
}