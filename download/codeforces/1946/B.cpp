#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

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
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define mod 1000000007

inline void work() {
    int n = rd(), k = rd();
    ll sum = 0, ans = -1e18, cur = 0;
    rep(i, 1, n) {
        int x = rd();
        sum += x;
        cur = max(cur, 0ll) + x;
        ans = max(ans, cur);
    }
    if (ans < 0) {
        printf("%lld\n", (sum % mod + mod) % mod);
        return;
    }
    sum = ((sum - ans) % mod + mod) % mod;
    ans = ans % mod;
    rep(i, 1, k) ans = (ans << 1) % mod;
    printf("%lld\n", (sum + ans) % mod);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}