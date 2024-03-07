#include <bits/stdc++.h>
using namespace std;
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

#define N 107

int a[N][N], vis[N];

inline void work() {
	int n = rd();
	vector<int> row, col;
	memset(vis, 0, sizeof(vis));
	rep(i, 1, n) {
		rep(j, 1, n) vis[a[i][j] = rd()] = i;
		bool fl = true;
		rep(j, 1, n) if (vis[j] != i) fl = false;
		if (fl) row.eb(i);
	}
	memset(vis, 0, sizeof(vis));
	rep(j, 1, n) {
		rep(i, 1, n) vis[a[i][j]] = j;
		bool fl = true;
		rep(i, 1, n) if (vis[i] != j) fl = false;
		if (fl) col.eb(j);
	}
	auto work = [&](int r, int c) {
		rep(w, 1, n) {
			a[r][c] = w;
			bool fl = false;
			memset(vis, 0, sizeof(vis));
			rep(j, 1, n) {
				if (vis[a[r][j]]) fl = true;
				vis[a[r][j]] = true;
			}
			if (!fl) continue;
			fl = false;
			memset(vis, 0, sizeof(vis));
			rep(i, 1, n) {
				if (vis[a[i][c]]) fl = true;
				vis[a[i][c]] = true;
			}
			if (!fl) continue;
			printf("%d %d %d\n", r, c, a[r][c]);
			return;	
		}
	};

	int ans = max(row.size(), col.size());
	printf("%d\n", ans);
	while (row.size() < ans) row.eb(1);
	while (col.size() < ans) col.eb(1);
	rep(i, 0, ans - 1) work(row[i], col[i]);
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}