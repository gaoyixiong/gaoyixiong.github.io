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

#define N 100007

int a[N];

inline void work() {
    int n = rd(), x = rd();
    rep(i, 1, n) a[i] = rd();
    auto check = [&](int x) {
        int nw = 0, res = 0;
        rep(i, 1, n) {
            nw ^= a[i];
            if ((nw & x) == nw) {nw = 0; ++res;}
        }
        return ((nw & x) == nw ? res : -1);
    };
    int lim = 0, ans = check(x);
    per(i, 29, 0) if ((x >> i) & 1) {
        lim += (1 << i);
        ans = max(ans, check(lim - 1));
    } 
    printf("%d\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}