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

#define N 400007

double f[N], sumf[N], g[N], sumg[N];

int main() {
    int n = rd(), l = rd(), d = rd();
    f[0] = sumf[0] = 1;
    rep(i, 1, n + d) {
        f[i] = (sumf[i - 1] - (i > d ? sumf[i - d - 1] : 0)) / d;
        sumf[i] = sumf[i - 1] + (i >= l ? 0 : f[i]);
    }
    double pfail = 0;
    rep(i, n + 1, n + d) pfail += f[i];
    rep(i, 0, l - 1) sumf[i] = pfail;
    rep(i, l, n) sumf[i] = sumf[i - 1] + f[i];  
    // sumf[i] = the probability dealer makes <= i or directly failed
    sumg[n] = g[n] = sumf[n - 1];
    per(i, n - 1, 1) {
        g[i] = max(sumf[i - 1], (sumg[i + 1] - sumg[i + d + 1]) / d);
        sumg[i] = sumg[i + 1] + g[i];
    }
    g[0] = max(pfail, (sumg[1] - sumg[d + 1]) / d);
    printf("%.10lf\n", g[0]);
    return 0;
}