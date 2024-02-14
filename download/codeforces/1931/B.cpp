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

int a[200007];

inline void work() {
    int n = rd();
    ll sum = 0;
    rep(i, 1, n) sum += (a[i] = rd());
    int avg = sum / n;
    rep(i, 1, n) {
        if (a[i] < avg) {puts("NO"); return;}
        a[i + 1] += a[i] - avg;
    }
    puts("YES");
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}