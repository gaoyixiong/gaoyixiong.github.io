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

constexpr int N = 27;

char s[N];

int a[N][N];

constexpr int dx[4] = {0, 0, 1, -1};
constexpr int dy[4] = {1, -1, 0, 0};

int main() {
	int h = rd(), w = rd();
	rep(i, 1, h) {
		scanf("%s", s + 1);
		rep(j, 1, w) a[i][j] = (s[j] == '#' ? 1 : 2);
	}
	rep(i, 1, h) rep(j, 1, w) if (a[i][j] == 1) {
		int num = 0;
		rep(k, 0, 3) num += (a[i + dx[k]][j + dy[k]] == 1);
		if (num != 2 && num != 4) {puts("No"); return 0;}
	}
	puts("Yes");
	return 0;	
}