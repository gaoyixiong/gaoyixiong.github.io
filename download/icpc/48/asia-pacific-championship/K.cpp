#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

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
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 100007

vector<int> son[N];

int n, sz[N], mxs[N];

ll ans[N];

void dfs1(int u) {
	sz[u] = 1;
	for (auto v : son[u]) {
		dfs1(v); sz[u] += sz[v];
		if (sz[v] > sz[mxs[u]]) mxs[u] = v;
	}
}

struct segtree {
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) / 2)
	int sum[N << 2];
	void upd(int rt, int l, int r, int pos, int w) {
		if (l == r) {sum[rt] = w; return;}
		pos <= mid ? upd(ls, l, mid, pos, w) : upd(rs, mid + 1, r, pos, w);
		sum[rt] = sum[ls] + sum[rs];
	}
	pii getk(int rt, int l, int r, int k) {
		if (l == r) return make_pair(l, k);
		if (sum[ls] >= k) return getk(ls, l, mid, k);
		else return getk(rs, mid + 1, r, k - sum[ls]);
	}
	int findk(int rt, int l, int r, int k) {
		if (l == r) return l;
		if (sum[ls] >= k) return findk(ls, l, mid, k);
		else return findk(rs, mid + 1, r, k - sum[ls]);
	}
} seg;

vector<pii> q1[N], q2s[N], q2mxs[N];

vector<tii> q2[N];

int tot, nxt[N];

void dfs2(int u) {
	seg.upd(1, 1, n, u, sz[u]);
	for (auto [qid, k] : q1[u]) {
		auto [lca, kk] = seg.getk(1, 1, n, k);
		ans[qid] += 1ll * (lca - 1) * n;
		if (lca == u) q2s[lca].eb(qid, kk);
		else if (nxt[lca] == mxs[lca]) q2mxs[lca].eb(qid, kk); 
		else q2[lca].eb(nxt[lca], qid, kk);
	}
	for (auto v : son[u]) {
		seg.upd(1, 1, n, u, sz[u] - sz[v]);
		dfs2(nxt[u] = v);
	}
	nxt[u] = 0;
	seg.upd(1, 1, n, u, 0);
}

void upd(int u, int w) {
	if (!u) return;
	seg.upd(1, 1, n, u, w);
	for (auto v : son[u]) upd(v, w);
}

void dfs3(int u, bool cancel) {

	for (auto v : son[u]) if (v != mxs[u]) dfs3(v, true);
	
	if (!q2mxs[u].empty()) { // answering queries for subtracting mxs
		seg.upd(1, 1, n, u, 1);
		for (auto v : son[u]) if (v != mxs[u]) upd(v, 1);
		for (auto [qid, k] : q2mxs[u]) ans[qid] += seg.findk(1, 1, n, k) - 1; 
		seg.upd(1, 1, n, u, 0);
		for (auto v : son[u]) if (v != mxs[u]) upd(v, 0);
	}

	// get all nodes inside subtree
	if (mxs[u]) dfs3(mxs[u], false);
	seg.upd(1, 1, n, u, 1);
	for (auto v : son[u]) if (v != mxs[u]) upd(v, 1);
	
	if (!q2s[u].empty()) {// answering queries for subtracting nobody
		for (auto [qid, k] : q2s[u]) 
			ans[qid] += seg.findk(1, 1, n, k) - 1; 
	}
	
	int lst = 0;
	sort(all(q2[u]));
	for (auto [v, qid, k] : q2[u]) {
		if (lst != v) {upd(lst, 1); upd(lst = v, 0);}
		ans[qid] += seg.findk(1, 1, n, k) - 1;
	}
	upd(lst, 1);

	if (cancel) upd(u, 0);
}

int main() {
	n = rd();
	int q = rd(), rt = 0;
	rep(i, 1, n) {
		int fa = rd();
		if (fa == 0) rt = i;
		else son[fa].eb(i);
	}
	dfs1(rt);
	rep(i, 1, q) {
		ll p = rd();
		ll x = (p + n - 1) / n;
		ans[i] += (x - 1) * n * n;
		q1[x].eb(i, p - (x - 1) * n);
	}
	dfs2(rt);
	dfs3(rt, false);
	rep(i, 1, q) printf("%lld\n", ans[i]);
	return 0;
}