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

int a[200007];

inline void work() {
    int n = rd();
    rep(i, 1, n) a[i] = rd();
    int pre = n, suf = n;
    rep(i, 2, n) if (a[i] != a[1]) {pre = i - 1; break;}
    per(i, n - 1, 1) if (a[i] != a[n]) {suf = n - i; break;}
    if (a[1] == a[n]) printf("%d\n", max(0, n - pre - suf));
    else printf("%d\n", n - max(pre, suf));
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}