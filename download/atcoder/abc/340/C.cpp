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

unordered_map<ll, ll> f;

ll dfs(ll w) {
    if (w < 2) return 0;
    if (f[w]) return f[w];
    return f[w] = (w + dfs(w / 2) + dfs(w - w / 2));
}

int main() {
    ll x; cin >> x; cout << dfs(x);
    return 0;
}