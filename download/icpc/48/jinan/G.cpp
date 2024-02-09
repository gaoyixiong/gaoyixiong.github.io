#include <bits/stdc++.h>
using namespace std;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 1000007
#define mod 1000000007

inline int fpow(int x, int t) {
    int res = 1;
    for (; t; t >>= 1, x = 1ll * x * x % mod)
        if (t & 1) res = 1ll * res * x % mod;
    return res;
}

char s[N];

int f[N << 1];

vector<int> pos[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}
void merge(int x, int y) {f[find(x)] = find(y);}

inline void work() {
    int n = rd(), m = rd();
    rep(i, 1, m) pos[i].clear();
    rep(i, 1, (n << 1)) f[i] = i;
    rep(i, 1, n) {
        scanf("%s", s + 1);
        rep(j, 1, m) if (s[j] == '1') pos[j].eb(i);
    }
    auto link1 = [&](int x, int y) {merge(x, y); merge(x + n, y + n);};
    auto link2 = [&](int x, int y) {merge(x, y + n); merge(x + n, y);};

    per(i, (m + 1) / 2, 1) {
        int j = m + 1 - i;
        int tot = pos[i].size() + pos[j].size();
        if (tot > 2) {puts("0"); return;}
        if (tot < 2) continue;
        if (pos[i].size() > 1) link2(pos[i][0], pos[i][1]);
        else if (pos[j].size() > 1) link2(pos[j][0], pos[j][1]);
        else if (i != j) link1(pos[i][0], pos[j][0]); 
    }

    rep(i, 1, n) if (find(i) == find(i + n)) {puts("0"); return;}

    int ans = 0;
    rep(i, 1, (n << 1)) if (f[i] == i) ++ans; 
    printf("%d\n", fpow(2, ans / 2));
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}