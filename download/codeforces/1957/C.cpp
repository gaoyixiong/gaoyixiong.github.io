#include <bits/stdc++.h>
using namespace std;

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

#define N 300007
#define mod 1000000007

int fac[N] = {1}, ifac[N] = {1};
 
inline int fpow(int x, int t = mod - 2) { 
    int ret = 1;
    for (; t; t >>= 1, x = 1ll * x * x % mod)
        if (t & 1) ret = 1ll * ret * x % mod;
    return ret;
}
 
inline void work() {
    int n = rd(), k = rd();
    rep(i, 1, k) rd() == rd() ? n -= 1 : n -= 2;
    auto calc = [&](int x) {
        return 1ll * fac[n] * ifac[n - 2 * x] % mod * ifac[x] % mod;
    };
    int ans = 0;
    rep(j, 0, n / 2) ans = (ans + calc(j)) % mod;
    printf("%d\n", ans);
}
 
int main() {
    rep(i, 1, N - 1) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[N - 1] = fpow(fac[N - 1]);
    per(i, N - 2, 1) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    per(t, rd(), 1) work();
    return 0;
}