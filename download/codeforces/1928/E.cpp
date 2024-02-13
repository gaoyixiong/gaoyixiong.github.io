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

int dp[N], pres[N], prel[N];

inline void init() {
    rep(i, 1, N - 1) dp[i] = 1e9;
    int sum = 0, len = 1;
    while (sum < N) {
        rep(v, sum, N - 1)
            if (dp[v] > dp[v - sum] + len) {
                dp[v] = dp[v - sum] + len;
                pres[v] = v - sum; prel[v] = len;
            }
        sum += len; ++len;
    }
}

inline void work() {

    int n = rd(), X = rd(), Y = rd(), S = rd();
    if (n == 1) {printf(X != S ? "NO\n" : "YES\n%d\n", X); return;}

    int r = X % Y;  
    if (S < X + 1ll * r * (n - 1) || (S - r * n) % Y != 0) {puts("NO"); return;}   
    int x = (X - r) / Y, s = (S - r * n) / Y;

    rep(i, 1, n) {
        s -= x; ++x; 
        if (s < 0) break;
        if (dp[s] <= n - i) {
            puts("YES");
            rep(j, 1, i) {printf("%d ", X); X += Y;}
            rep(j, i + dp[s] + 1, n) printf("%d ", r);
            for (; s; s = pres[s]) {
                int cur = r;
                per(j, prel[s], 1) {printf("%d ", cur); cur += Y;}
            }
            puts(""); return;
        }
    }
    puts("NO");
}

int main() {
    init();
    per(t, rd(), 1) work();
    return 0;
}