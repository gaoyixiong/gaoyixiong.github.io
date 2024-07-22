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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

inline void work() {
    int x = rd(), y = rd();
    if (x > y) swap(x, y);
    if (x % 2 == 0) {puts("Yes"); return;}
    if (y % 2 == 0 && y != x * 2) puts("Yes");
    else puts("No");
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}