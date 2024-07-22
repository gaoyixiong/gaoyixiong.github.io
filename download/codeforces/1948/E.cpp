#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k = min(n, k);

        auto calc = [&](int st, int l) {
            int L = l / 2;
            rep(i, 1, L) printf("%d ", L - i + 1 + st);
            rep(i, L + 1, l) printf("%d ", l + L + 1 - i + st);
        };

        int cur = 0, ans = 0;
        while (cur < n) {
            ++ans;
            int l = min(k, n - cur);
            calc(cur, l); cur += l; 
        }
        puts("");
        printf("%d\n", ans);
        int cnt = 1;
        rep(i, 1, n) {
            printf("%d ", cnt);
            if (i % k == 0) ++cnt;
        }
        puts("");
    }
    return 0;
}