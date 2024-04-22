#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

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
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

vector<int> s;

inline void work() {
    s.clear();
    int n = rd();
    rep(i, 1, n) s.eb(rd());
    sort(all(s));
    int tar = (n - 1) / 2, ans = 0;
    for (int pos = tar; pos < n && s[pos] == s[tar]; ++ans, ++pos);
    printf("%d\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}