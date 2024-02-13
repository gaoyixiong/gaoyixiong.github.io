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

vector<int> a;

inline void work() {
    a.clear();
    int n = rd();
    rep(i, 1, n) a.eb(rd());
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    int ptr = 0, cur = 0, ans = 0;
    for (auto x : a) {
        ++cur;
        while (a[ptr] <= x - n) ++ptr;
        ans = max(ans, cur - ptr);
    }
    printf("%d\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}