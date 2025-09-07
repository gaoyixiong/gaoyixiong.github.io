#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

constexpr int N = 5007;

ll dp[N][N], w[N];

vector<int> e[N];

int main() {
	memset(dp, 0x3f, sizeof(dp));
	ll inf = dp[0][0];
	int n = rd(), m = rd();
	rep(i, 1, n) w[i] = rd();
	rep(i, 1, m) {
		int u = rd(), v = rd();
		e[u].eb(v); e[v].eb(u);
	}
	rep(i, 0, m) dp[1][i] = 0;
	per(i, m, 1) rep(u, 1, n) if (dp[u][i] != inf) {
		for (auto v : e[u]) 
			dp[v][i - 1] = min(dp[v][i - 1], dp[u][i] + w[u] * i);
	}
	rep(i, 1, n) printf("%lld\n", dp[i][0]);
	return 0;
}