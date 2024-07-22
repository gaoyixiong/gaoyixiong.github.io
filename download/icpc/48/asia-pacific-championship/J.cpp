#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mp make_pair

inline int rd() {
    int x = 0; bool f = 0; char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define M 600007
#define N 200007
vector<pii> e[N];
int pre[N], pree[N];

struct node {
    int u, dis;
    bool operator < (const node &a) const {return a.dis < dis;}
};

int dis[N], vis[N];

void dij(int s, int n, int op) {
    priority_queue<node> q;
    q.push(node{s, 0});
    for (int i = 1; i <= n; ++i) {
        dis[i] = 1e9; vis[i] = 0;
    }
    dis[s] = 0;
    while(!q.empty()) {
        node a = q.top(); q.pop();
        int nw = a.u;
        if (vis[nw]) continue;
        vis[nw] = 1;
        for (auto [v, w] : e[nw]) {
            if (dis[nw] + w < dis[v]) {
                dis[v] = dis[nw] + w;
                if (op) pree[v] = nw;
                q.push(node{v, dis[v]});
            }
        }
    }
}

int main() {
    int n = rd(), m = rd();
    for (int i = 1; i <= m; ++i) {
        int u = rd(), v = rd(), w = rd();
        e[u].pb(mp(v, w)); e[v].pb(mp(u, w));
    }
    dij(1, n, 1);
    int ans = dis[n];
    if (ans == 1e9) {puts("-1"); return 0;}
    // printf("%d\n", ans);
    for (int t = n; t != 1; t = pree[t]) pre[t] = pree[t]; 
    for (int u = 1; u <= n; ++u)
        for (auto [v, w] : e[u]) {
            if (pre[u] == v) continue;
            if (pre[v] == u) {
                e[u + n].pb(mp(v + n, w));
                e[v + n].pb(mp(u + n, w));
            } else {
                e[u + n].pb(mp(v, w));
                e[v + n].pb(mp(u, w));
            }
        }
    dij((n << 1), (n << 1), 0);
    if (dis[1] == 1e9) {puts("-1"); return 0;}
    ans += dis[1];
    printf("%d\n", ans);
    return 0;
}