#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;


inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 500007

int a[N];

void printt(ll x) {
	if (!x) return;
	int c = x % 10;
	printt(x / 10);
	printf("%d", c);
}

void print(ll x) {
	int c = x % 10;
	printt(x / 10);
	printf("%d\n", c);
}

inline void work() {
	int n = rd(), b[200];
	memset(b, -1, sizeof(b));
	
	rep(i, 1, n) a[i] = rd();

	if (n == 1) {printf("%lld\n", (1ll << a[1]) - 1); return;}

	if (a[2] == a[1] + 1) b[0] = 0;
	else {
		if (a[2] > a[1]) {puts("-1"); return;}
		b[0] = 1;
	}
	
	rep(i, 2, n) {
		if (b[0] == 1) {
			if (a[i] > a[i - 1]) {puts("-1"); return;}
			int cnt = a[i - 1] - a[i];
			rep(j, 0, cnt) {
				if (b[j] == -1) b[j] = 1;
				if (b[j] != 1) {puts("-1"); return;} 
			}
			if (b[cnt + 1] == -1) b[cnt + 1] = 0;
			if (b[cnt + 1] != 0) {puts("-1"); return;}
			rep(j, 0, cnt) b[j] = 0;
			b[cnt + 1] = 1;
		} else {
			b[0] = 1;
			if (a[i] - a[i - 1] != 1) {puts("-1"); return;}
		}
	}
	b[0] -= n - 1;
	for (int idx = 0; b[idx] < 0; ++idx) {
		b[idx + 1] -= (1 - b[idx]) / 2;
		b[idx] &= 1;
	}

	int cnt1 = 0, idx = 0;
	for (; b[idx] != -1; ++idx) cnt1 += b[idx];


	if (cnt1 > a[1]) {puts("-1"); return;}
	rep(i, cnt1, a[1] - 1) b[idx++] = 1;
	ll ans = 0;
	per(i, idx - 1, 0) ans = (ans << 1) + b[i];
	print(ans); 
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}