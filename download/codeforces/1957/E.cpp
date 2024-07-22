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

#define N 1000007
#define mod 1000000007

bool vis[N];

int ans[N];

int main() {
    auto mo = [&](int x) {return x >= mod ? x - mod : x;};
    auto calc = [&](int p) {
        int nw = p - 1;
        for (int j = p; j < N; j += p) {
            vis[j] = true;
            ans[j] = mo(ans[j] + nw);
            if (j + p < N) ans[j + p] = mo(ans[j + p] + mod - nw);
            nw = (nw == 0 ? p - 1 : nw - 1);
        }
    };
    rep(i, 2, N - 1) if (!vis[i]) calc(i);
    for (int j = 4; j < N; j += 8) {
        ans[j] = mo(ans[j] + 2);
        if (j + 4 < N) ans[j + 4] = mo(ans[j + 4] + mod - 2);
    }
    rep(i, 1, N - 1) ans[i] = mo(ans[i] + ans[i - 1]);
    rep(i, 1, N - 1) ans[i] = mo(ans[i] + ans[i - 1]);
    per(t, rd(), 1) printf("%d\n", ans[rd()]);
    return 0;
}