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

#define N 2000007
#define mod 998244353

int fac[N], ifac[N];

inline int fpow(int x, int t = mod - 2) {
    int res = 1;
    for (; t; t >>= 1, x = 1ll * x * x % mod)
        if (t & 1) res = 1ll * res * x % mod;
    return res;
}

inline void init() {
    fac[0] = ifac[0] = 1;
    rep(i, 1, N - 1) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[N - 1] = fpow(fac[N - 1]);
    per(i, N - 2, 1) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}

inline int C(int n, int k) {
    if (n < k) return 0;
    return 1ll * fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

inline void work() {
    int c1 = rd(), c2 = rd(), c3 = rd(), c4 = rd();
    if (c1 == 0 && c2 == 0) {
        puts((c3 != 0 && c4 != 0) ? "0" : "1");
        return;
    }
    if (abs(c1 - c2) > 1) {puts("0"); return;}
    if (c1 != c2) {
        int pos = max(c1, c2);
        printf("%lld\n", 1ll * C(pos + c3 - 1, c3) * C(pos + c4 - 1, c4) % mod);
    } else {
        int ans1 = 1ll * C(c1 + c3, c3) * C(c1 + c4 - 1, c4) % mod;
        int ans2 = 1ll * C(c1 + c3 - 1, c3) * C(c1 + c4, c4) % mod;
        printf("%d\n", (ans1 + ans2) % mod);
    }
}

int main() {
    init();
    per(t, rd(), 1) work();
    return 0;
}