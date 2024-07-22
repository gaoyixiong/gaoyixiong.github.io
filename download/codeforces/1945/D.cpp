#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

inline int rd() {
    int x = 0;
    bool f = 0; 
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c== '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

int a[N];

ll sum[N];

inline void work() {
    int n = rd(), m = rd();
    ll ans = 1e18;
    rep(i, 1, n) a[i] = rd();
    rep(i, 1, n) sum[i] = sum[i - 1] + min(a[i], rd());
    rep(i, 1, m) ans = min(ans, a[i] + sum[n] - sum[i]);
    printf("%lld\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}