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

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 1007

int x[N], y[N], r[N], col[N], cnt[2];

vector<int> e[N];

bool fl;

void dfs(int u, int c) {
    if (col[u] != -1) {if (col[u] != c) fl = true; return;}
    ++cnt[col[u] = c];
    for (auto v : e[u]) dfs(v, 1 - c);
}

int main() {
    int n = rd();
    rep(i, 1, n) x[i] = rd(), y[i] = rd(), r[i] = rd();
    auto sqr = [&](int x) {return 1ll * x * x;};
    rep(i, 1, n) rep(j, i + 1, n) 
        if (sqr(x[i] - x[j]) + sqr(y[i] - y[j]) == sqr(r[i] + r[j])) {
            e[i].eb(j); e[j].eb(i);
        }
    rep(i, 1, n) col[i] = -1;
    rep(i, 1, n) if (col[i] == -1) {
        fl = false;
        cnt[0] = cnt[1] = 0; dfs(i, 0);
        if (!fl && cnt[0] != cnt[1]) {puts("YES"); return 0;}
    }
    puts("NO");
    return 0;
}