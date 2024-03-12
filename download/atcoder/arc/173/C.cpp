#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

inline ll rd() {
    ll x = 0;
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

int a[N];

int main() {
    int n = rd();
    rep(i, 1, n) a[i] = rd();
    // calculate answer for a[1]
    int sum = 0, ans = -1;
    rep(i, 2, n) {
        sum += (a[i] > a[1] ? 1 : -1);
        if ((i & 1) && (sum != 0)) {ans = i; break;}
    }
    printf("%d ", ans);

    auto calc = [&](int p) {
        if ((a[p - 1] < a[p]) == (a[p + 1] < a[p])) {printf("3 "); return;}
        int L = p - 1, R = p + 1, ans = n + 1;
        while (L > 1 && ((a[L - 1] < a[p]) != (a[L] < a[p]))) --L;
        if (L > 1) ans = min(ans, (p + 2 - L) / 2 * 2 + 1);
        while (R < n && ((a[R + 1] < a[p]) != (a[R] < a[p]))) ++R;
        if (R < n) ans = min(ans, (R + 2 - p) / 2 * 2 + 1);
        printf("%d ", (ans <= n ? ans : -1));
    }; 

    rep(i, 2, n - 1) calc(i);

    sum = 0; ans = -1;
    per(i, n - 1, 1) {
        sum += (a[i] > a[n] ? 1 : -1);
        if (((n - i + 1) & 1) && (sum != 0)) {ans = n - i + 1; break;}
    }
    printf("%d", ans);
    return 0;
}