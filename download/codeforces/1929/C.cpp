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
    ll k = rd(), x = rd() + 1, a = rd();
    ll sum = 0;
    rep(i, 1, x) {
        int putin = sum / (k - 1) + 1;
        sum += putin;
        if (sum > a) {puts("NO"); return;}
    }
    puts("YES");
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}