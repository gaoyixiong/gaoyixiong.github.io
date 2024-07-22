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

inline void work() {
    int n = rd(), k = rd();
    if (n == 1) {printf("%d\n", k); return;}
    int i = 0;
    for (; (1 << i) <= k + 1; ++i);
    --i; 
    printf("%d %d ", (1 << i) - 1, k - (1 << i) + 1);
    rep(i, 3, n) printf("%d ", 0); puts("");
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}