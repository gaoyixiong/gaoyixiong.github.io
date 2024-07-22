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

int a[N], pl[N], pr[N];

char s[N];

inline void work() {
    int n = rd(), m = rd();
    rep(i, 1, n) a[i] = rd();
    int L = 1, R = n;
    scanf("%s", s + 1);
    rep(i, 1, n - 1) s[i] == 'L' ? ++L : --R;
    pl[L] = a[L]; pr[L] = 1;
    per(i, L - 1, 1) pl[i] = 1ll * pl[i + 1] * a[i] % m;
    rep(i, L + 1, n) pr[i] = 1ll * pr[i - 1] * a[i] % m;
    printf("%lld ", 1ll * pl[1] * pr[n] % m);
    L = 1; R = n;
    rep(i, 1, n - 1) {
        s[i] == 'L' ? ++L : --R;
        printf("%lld ", 1ll * pl[L] * pr[R] % m);
    }
    puts("");
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}