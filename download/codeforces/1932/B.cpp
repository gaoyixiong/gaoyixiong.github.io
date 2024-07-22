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

#define N 10007

inline void work() {
    int n = rd();
    ll ans = 0;
    rep(i, 1, n) {
        int a = rd();
        ans = (ans / a + 1) * a;
    }
    printf("%lld\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}