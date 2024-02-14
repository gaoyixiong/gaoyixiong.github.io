#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

map<pii, int> f;

inline void work() {
    f.clear();
    ll ans = 0;
    int n = rd(), x = rd(), y = rd();
    rep(i, 1, n) {
        int w = rd();
        int a = w % x, b = w % y;
        ans += f[{(x - a) % x, b}];
        ++f[{a, b}];
    }
    printf("%lld\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}