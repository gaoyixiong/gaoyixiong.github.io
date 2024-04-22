#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

inline ll rd() {
    ll x = 0;
    bool f = 0; 
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c== '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 300007

int sum[N];

inline void work() {
    int n = rd();
    rep(i, 1, n) {
        char c = getchar();
        while (!isdigit(c)) c = getchar();
        sum[i] = sum[i - 1] + (c == '1');
    }
    int ans = -1;
    rep(i, 0, n) {
        int L = i, R = n - i;
        int LL = L - sum[i], RR = sum[n] - sum[i];
        if (LL * 2 < L || RR * 2 < R) continue;
        if (abs(n - i * 2) < abs(n - ans * 2)) ans = i;
    }
    printf("%d\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}