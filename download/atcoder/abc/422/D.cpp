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

int dif;

vector<int> ans;

void divide(int l, int r, int a, int rem) {
	if (l == r) {ans.eb(a + (rem > 0)); return;}
	int mid = (l + r) / 2;
	divide(l, mid, a, rem / 2);
	divide(mid + 1, r, a, rem - rem / 2);
	dif = max(dif, rem & 1);
}

int main() {
	int n = rd(), k = rd();
	int pos = (1 << n);
	int ave = k / pos, rem = k % pos;
	dif = (rem > 0);
	divide(1, pos, ave, rem);
	printf("%d\n", dif);
	for (auto x : ans) printf("%d ", x);
	return 0;
}