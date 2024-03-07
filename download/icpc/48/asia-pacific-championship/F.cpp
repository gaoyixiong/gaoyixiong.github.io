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

inline int max(const int &a, const int &b) {return a < b ? b : a;}
inline int min(const int &a, const int &b) {return a < b ? a : b;}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 1000007

int a[N], c[N];

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

inline void work() {
	int n = rd(), q = 1, p = 1000000000;
	rep(i, 0, n - 1) a[i] = rd();

	auto check = [&](int _p, int _q) {
		if (1ll * _p * q < 1ll * p * _q) {p = _p; q = _q;}
	};

	auto calc = [&](int d) {
		static int hdmx, tlmx, qmx[N];
		static int hdmn, tlmn, qmn[N];
		hdmx = hdmn = 1;
		tlmx = tlmn = 0;
		auto insmx = [&](int pos) {
			while (hdmx <= tlmx && c[pos] >= c[qmx[tlmx]]) --tlmx;
			qmx[++tlmx] = pos;
		};
		auto insmn = [&](int pos) {
			while (hdmn <= tlmn && c[pos] <= c[qmn[tlmn]]) --tlmn;
			qmn[++tlmn] = pos;
		};
		rep(i, 1, d) c[i] = 0;
		rep(i, 0, n - 1) c[i % d + 1] += a[i];
		rep(i, 1, d) insmx(i), insmn(i); 
		check(c[qmx[hdmx]], c[qmn[hdmn]]);

		if (hdmx <= tlmx && qmx[hdmx] == 1) ++hdmx;
		if (hdmn <= tlmn && qmn[hdmn] == 1) ++hdmn;
			
		rep(i, 1, n - 1) {
			int pre = (i - 1) % d + 1, cur = i % d + 1;
			if (hdmx <= tlmx && qmx[hdmx] == cur) ++hdmx; 
			if (hdmn <= tlmn && qmn[hdmn] == cur) ++hdmn;
			c[pre] += a[i] - a[0]; c[cur] += a[0] - a[i]; 
			insmx(pre); insmn(pre);
			check(max(c[cur], c[qmx[hdmx]]), min(c[cur], c[qmn[hdmn]]));
		}	
	};

	int m = n;
	for (int i = 2; i <= m; ++i) if (m % i == 0) {
		calc(i); while (m % i == 0) m /= i;
	}
	int g = gcd(p, q);
	printf("%d %d\n", p / g, q / g);
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}