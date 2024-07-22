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

int a[500007];

multiset<int> small, big;

inline void work() {
	small.clear(); big.clear();
	int n = rd(), ans = 0, R = 0;
	ll k = rd(), sums = 0, sumb = 0;

	// kept small.size() <= big.size() <= smalls.size() + 1
	auto balance = [&]() {
		while (big.size() < small.size()) {
			int w = *--small.end();
			big.insert(w);
			small.erase(--small.end());
			sums -= w; sumb += w;
		}
		while (big.size() > small.size() + 1) {
			int w = *big.begin();
			small.insert(w);
			big.erase(big.begin());
			sums += w; sumb -= w;
		}
	};

	auto del = [&](int w) {
		if (!big.empty() && w >= *big.begin()) {big.erase(big.find(w)); sumb -= w;}
		else {small.erase(small.find(w)); sums -= w;}
		balance();
	};

	auto add = [&](int w) {
		if (!big.empty() && w >= *big.begin()) {big.insert(w); sumb += w;}
		else {small.insert(w); sums += w;}
		balance();
	};

	auto check = [&]() {
		return (*big.begin()) * ((int)small.size() - (int)big.size()) - sums + sumb <= k;
	};

	rep(i, 1, n) a[i] = rd() - i;
	rep(i, 1, n) {
		if (R < i) add(a[++R]);
		if (i > 1) del(a[i - 1]);
		while (R <= n && check()) add(a[++R]);
		ans = max(ans, R - i);
	}
	printf("%d\n", ans);
}

int main() {
	per(t, rd(), 1) work();	
	return 0;
}