#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define mod 998244353

#define N 1000007

int fac[N], ifac[N];

inline int fpow(int x, int t = mod - 2) {
    int res = 1;
    for (; t; t >>= 1, x = 1ll * x * x % mod)
        if (t & 1) res = 1ll * res * x % mod;
    return res;
}

inline int C(int n, int m) {
    return n < m ? 0 : 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int psum[N], a[N], b[N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    fac[0] = ifac[0] = 1;
    rep(i, 1, N - 1) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[N - 1] = fpow(fac[N - 1]);
    per(i, N - 2, 1) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    int n, q; cin >> n >> q;
    rep(i, 1, n) {cin >> a[i]; a[i] += a[i - 1];}
    rep(i, 1, n) {cin >> b[i]; b[i] += b[i - 1];}
    psum[0] = 1;
    rep(i, 1, b[n]) psum[i] = (psum[i - 1] + C(b[n], i)) % mod;
    int bs = fpow(fpow(2, b[n]));
    rep(i, 1, q) {
        int l, r; 
        cin >> l >> r;
        int xi = a[r] - a[l - 1];
        int yi = b[r] - b[l - 1];
        int xj = a[n] - xi, yj = b[n] - yi;
        int d = xj - xi;
        if (yi <= d) {printf("0 "); continue;}
        if (yj + d < 0) {printf("1 "); continue;}
        printf("%lld ", 1ll * bs * psum[min(yi, yi - 1 - d)] % mod);
    }
    return 0;
}