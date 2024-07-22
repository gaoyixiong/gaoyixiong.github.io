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

inline void work() {
    int a = rd(), b = rd(), c = rd();
    int ans = a + b / 3;
    b = b % 3;
    if (c < (3 - b) % 3) {puts("-1"); return;}
    ans += (c + b + 2) / 3;
    printf("%d\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}