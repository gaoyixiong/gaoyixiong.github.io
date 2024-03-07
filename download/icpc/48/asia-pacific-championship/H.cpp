#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll rd() {
	ll x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 100007

char s[N << 1];

int a[N], b[N];

int main() {
	int n = rd(), ans = 0;
	bool f1 = false, f2 = false;
	bool h1 = false, h2 = false;
	rep(i, 1, n) {
		scanf("%s", s + 1);
		int l = strlen(s + 1);
		rep(j, 1, l) a[i] += (s[j] == '1');
		b[i] = l - a[i];
		if (a[i]) h1 = true;
		if (b[i]) h2 = true;
		if (a[i] == b[i]) {f1 = f2 = true; ans += a[i];}
		else if (a[i] < b[i]) {f2 = true; ans += a[i];}
		else {f1 = true; ans += b[i];}
	}
	if (!f1 && h1) {
		int mnc = 1e9;
		rep(i, 1, n) mnc = min(mnc, b[i] - a[i]);
		ans += mnc;
	}
	if (!f2 && h2) {
		int mnc = 1e9;
		rep(i, 1, n) mnc = min(mnc, a[i] - b[i]);
		ans += mnc;
	}
	printf("%d\n", ans);
	return 0;
}