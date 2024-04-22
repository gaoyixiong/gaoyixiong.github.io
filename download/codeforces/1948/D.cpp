#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 5007

int f[N][N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.length();
        auto check = [&](char a, char b) {
            return (a == '?' || b == '?' || a == b);
        };
        rep(i, 1, n + 1) f[i][n + 1] = f[n + 1][i] = 0;
        per(i, n, 1) per(j, n, i + 1) 
            f[i][j] = (check(s[i - 1], s[j - 1]) ? f[i + 1][j + 1] + 1 : 0);
        int ans = 0;
        rep(i, 1, n) rep(j, i + 1, n) 
            if (f[i][j] >= j - i) ans = max(ans, (j - i) * 2);
        printf("%d\n", ans);
    }
    return 0;
}