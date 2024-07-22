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

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 100007
 
int pre[30], suf[30], a[N], b[N];
 
inline void work() {
    memset(pre, 0, sizeof(pre));
    memset(suf, 0, sizeof(suf));
    int n = rd();
    rep(i, 1, n) {
        b[i] = b[i - 1] ^ (a[i] = rd());
        rep(j, 0, 29) if ((b[i] >> j) & 1) ++suf[j];
    }
    ll ans = 0;
    rep(i, 1, n) {
        int t = 30;
        for (; ; --t) if ((a[i] >> t) & 1) break;
        ans += 1ll * pre[t] * suf[t] + 1ll * (i - pre[t]) * (n - i + 1 - suf[t]);
        rep(j, 0, 29) if ((b[i] >> j) & 1) ++pre[j], --suf[j];
    }
    printf("%lld\n", ans);
}
 
int main() {
    per(t, rd(), 1) work();
    return 0;
}