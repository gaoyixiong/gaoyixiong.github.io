#include <bits/stdc++.h>
using namespace std;

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

map<int, int> f;

inline void work() {
    f.clear();
    int n = rd(), ans = 0;
    rep(i, 1, n) ++f[rd()];
    for (auto [a, b] : f) ans += b / 3;
    printf("%d\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}