#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

inline int rd() {
    int x = 0;
    bool f = 0; 
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c== '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

int a[N], pos[N];

inline void work() {
    int n = rd(), x = rd();
    rep(i, 1, n) pos[a[i] = rd()] = i;
    int l = 1, r = n + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        a[m] <= x ? l = m : r = m;
    }
    if (a[l] == x) {puts("0"); return;}
    puts("1");
    printf("%d %d\n", l, pos[x]);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}