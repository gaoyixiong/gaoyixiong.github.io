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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

inline void work() {
    int n = rd(), mx = 0, mn = 1e9 + 1;
    rep(i, 1, n) {
        int x = rd();
        mx = max(mx, x);
        mn = min(mn, x);
    }
    printf("%d\n", mx - mn);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}