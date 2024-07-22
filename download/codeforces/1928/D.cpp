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

#define N 200007

ll c[N], cnt[N], dlt[N];

inline void work() {
    ll n = rd(), b = rd(), x = rd(), mx = 0;
    rep(i, 1, n) mx = max(mx, c[i] = rd());
    rep(i, 1, mx) cnt[i] = dlt[i] = 0;
    rep(i, 1, n) {
        ll totcnt = c[i] * (c[i] - 1) / 2;
        rep(j, 1, c[i] - 1) {
            ll wa = c[i] / j, b = c[i] % j;
            ll wb = wa + 1, a = j - b;
            cnt[j] += totcnt - wa * (wa - 1) / 2 * a - wb * (wb - 1) / 2 * b;
        }
        dlt[c[i]] += totcnt;
    }
    ll ans = 0;
    rep(i, 1, mx) {
        dlt[i] += dlt[i - 1];
        ans = max(ans, (cnt[i] + dlt[i]) * b - (i - 1) * x);
    }
    printf("%lld\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}