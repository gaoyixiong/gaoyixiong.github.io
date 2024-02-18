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

ll a[N], s[N], t[N];

int main() {
    int n = rd();
    rep(i, 1, n) a[i] = rd();
    rep(i, 1, n - 1) {s[i] = rd(); t[i] = rd();}
    rep(i, 1, n - 1) a[i + 1] += (a[i] / s[i] * t[i]);
    printf("%lld\n", a[n]); 
    return 0;
}