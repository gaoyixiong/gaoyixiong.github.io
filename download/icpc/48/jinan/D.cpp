#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

inline void work() {
    int la = rd(), ra = rd(), lb = rd(), rb = rd();
    if (ra + rb - la - lb >= 10) {puts("9"); return;}
    auto check = [&](int w) {
        int ret = 0;
        while (w) {ret = max(ret, w % 10); w /= 10;}
        return ret;
    };
    int ans = 0;
    rep(i, la + lb, ra + rb) ans = max(ans, check(i));
    printf("%d\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}