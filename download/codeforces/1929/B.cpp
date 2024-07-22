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
    int n = rd(), w = rd();
    if (w <= 4 * n - 4) printf("%d\n", (w + 1) / 2);
    else printf("%d\n", w - 2 * n + 2);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}