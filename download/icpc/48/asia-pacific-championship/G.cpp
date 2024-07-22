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

#define N 5007

char str[N];

// solution1 : Pigeonhole principle

int w[N][N];

vector<int> pos[3000][26];

int main() {
	int n = rd(), m = rd(), k = rd();
	rep(i, 1, n) {
		scanf("%s", str);
		rep(j, 0, m - 1) if (str[j] != '.') {
			int c = str[j] - 'A';
			for (auto x : pos[j][c]) ++w[x][i];
			pos[j][c].eb(i);
		}
		per(j, i - 1, 1) 
			if (w[j][i] >= k) {printf("%d %d\n", j, i); return 0;}
	}
	puts("-1");
	return 0;
}

/* solution2 : bitset + dp

bitset<5001> f[6], id[3000][26];

int main() {
	int n = rd(), m = rd(), K = rd();
	rep(i, 1, n) {
		scanf("%s", str);
		f[0].set(); 
		rep(k, 1, K) f[k].reset();
		rep(j, 0, m - 1) 
			if (str[j] != '.') 
				per(k, K, 1) f[k] |= (f[k - 1] & id[j][str[j] - 'A']);
		if (f[K].count()) 
			per(j, i - 1, 1) 
				if (f[K][j]) {printf("%d %d\n", j, i); return 0;}
		rep(j, 0, m - 1) 
			if (str[j] != '.') id[j][str[j] - 'A'][i] = true;
	}
	puts("-1");
	return 0;
}

*/