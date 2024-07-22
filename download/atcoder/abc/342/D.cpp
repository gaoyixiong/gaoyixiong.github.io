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

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

int cnt[N];

int main() {
    ll ans = 0;
    int n = rd();
    rep(i, 1, n) {
        int x = rd();
        if (x == 0) {++cnt[0]; ans += i - 1; continue;}
        int lim = sqrt(x), rem = 1;
        rep(d, 2, lim) if (x % d == 0) {
            int cnt = 0;
            while (x % d == 0) {++cnt; x /= d;}
            if (cnt & 1) rem *= d;
        } 
        if (x > 1) rem *= x;
        ans += cnt[rem] + cnt[0];
        ++cnt[rem];
    }
    printf("%lld\n", ans);
    return 0;
}