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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007
#define M 300007

inline bool getmin(int &a, int b) {return (a > b ? (a = b, true) : false);}
inline bool getmax(int &a, int b) {return (a < b ? (a = b, true) : false);}
 
// F is the type of flow
template<const int V, const int E, class F, const F flowInf>
struct MF {
    int tot = 1, S, T, hd[V], cur[V], dis[V];
    struct edge{int to, nxt; F cap;} e[E << 1];
    void clear(int n) {
    	tot = 1; S = 0; T = n + 1;
    	rep(i, S, T) hd[i] = 0;
    }
    void add(int u, int v, F w) {
        e[++tot].nxt = hd[u], hd[u] = tot, e[tot].to = v, e[tot].cap = w;
        e[++tot].nxt = hd[v], hd[v] = tot, e[tot].to = u, e[tot].cap = 0;
    }
    inline bool bfs() {
        static int q[V], qhd, qtl; 
        rep(i, S, T) cur[i] = hd[i], dis[i] = -1;
        q[qhd = qtl = 1] = S; dis[S] = 0;
        while (qhd <= qtl) {
            int u = q[qhd++];
            for (int i = hd[u], v; i; i = e[i].nxt)
                if (dis[v = e[i].to] == -1 && e[i].cap != 0) {
                    dis[v] = dis[u] + 1; q[++qtl] = v;
                }
        }
        return dis[T] != -1;
    }
    F dfs(int u, F rem) {
        if (u == T) return rem;
        F flow = 0;
        for (int i = cur[u], v; i && rem; i = e[i].nxt) {
            cur[u] = i; v = e[i].to;
            F nw = min(rem, e[i].cap);
            if (nw != 0 && dis[v] == dis[u] + 1) {
                int ret = dfs(v, nw);
                flow += ret; rem -= ret; 
                e[i].cap -= ret; e[i ^ 1].cap += ret;
            }
        }
        if (flow == 0) dis[u] = -1;
        return flow;
    }
    F dinic() {
        F flow = 0;
        while (bfs()) flow += dfs(S, flowInf);
        return flow;
    }
    bool vis[V];
    int count(int u, int l, int r, int w) {
    	int ret = 0;
    	rep(i, S, T) vis[i] = 0;
		static int q[V], qhd, qtl; 
        q[qhd = qtl = 1] = u; vis[u] = 0;
        while (qhd <= qtl) {
            int u = q[qhd++];
            for (int i = hd[u], v; i; i = e[i].nxt)
                if (e[i].cap == w && !vis[v = e[i].to]) {
                    vis[v] = true; q[++qtl] = v;
                    if (v >= l && v <= r) ++ret;
                }
        }
        return ret;
    }
};

MF<N, M, int, 1000000000> g;

set<pii> e;

inline void work() {
	int n = rd(), m = rd();
	e.clear(); g.clear(n << 1);
	rep(i, 1, n) g.add(g.S, i, 1), g.add(i + n, g.T, 1);
	rep(i, 1, m) {
		int u = rd(), v = rd(); 
		if (e.find({u, v}) != e.end()) continue;
		g.add(u, v + n, 1); e.insert({u, v});
	}
	g.dinic();
	printf("%lld\n", 1ll * g.count(g.S, 1, n, 1) * g.count(g.T, n + 1, n * 2, 0));
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}