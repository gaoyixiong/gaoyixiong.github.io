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

inline void work() {
    int sum = rd();
    rep(i, 1, 26) rep(j, 1, 26) if (i + j < sum && sum - i - j <= 26) {
        putchar('a' + i - 1);
        putchar('a' + j - 1);
        putchar('a' + sum - i - j - 1); 
        puts(""); return;
    }
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}