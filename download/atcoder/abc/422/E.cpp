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

constexpr int N = 500007;

ll x[N], y[N];

int main() {
	int n = rd();
	rep(i, 1, n) x[i] = rd(), y[i] = rd();
	srand(time(0));
	auto test = [&](int a, int b) {
		int cnt = 0;
		ll dx = x[b] - x[a];
		ll dy = y[b] - y[a];
		rep(i, 1, n) {
			if (i == a || i == b) {++cnt; continue;}
			if (dx * (y[i] - y[a]) == dy * (x[i] - x[a])) ++cnt;
		}
		return cnt * 2 > n;
	};
	rep(i, 1, 100) {
		int a = rand() % n + 1;
		int b = rand() % n + 1;
		while (b == a) b = rand() % n + 1;
		if (test(a, b)) {
			ll A = y[b] - y[a];
			ll B = x[a] - x[b];
			ll C = -x[a] * A - y[a] * B; 
			printf("Yes\n%lld %lld %lld\n", A, B, C);
			return 0;
		}
	}
	puts("No");
	return 0;
}